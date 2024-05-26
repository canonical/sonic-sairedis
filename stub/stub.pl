#!/usr/bin/perl

use strict;
use warnings;
use diagnostics;
use sort 'stable';

use Getopt::Std;
use Data::Dumper;
use Term::ANSIColor;

my %options = ();
getopts("d:", \%options);

my $optionSaiDir = $options{d} if defined $options{d};
my $optionVariable = "stub";

# TODO to params
my $VAR = $optionVariable;
my $CLASS = "Sai";
my $NS = "sairedis";
my $FILE = "redis.cpp";

my $DATA = "";
my @OBJECT_TYPES = ();
my %objectTypes = ();
my @APIS = ();
my @FUNCTIONS = ();
my %FUNCTIONS = ();
my @globalApis = ();
my @apiStructs = ();
my %apiStructs = ();

my $SOURCE_CONTENT = "";

my $warnings = 0;
my $errors = 0;

sub LogInfo
{
    print color('bright_green') . "@_" . color('reset') . "\n";
}

sub LogWarning
{
    $warnings++;
    print color('bright_yellow') . "WARNING: @_" . color('reset') . "\n";
}

sub LogError
{
    $errors++;
    print color('bright_red') . "ERROR: @_" . color('reset') . "\n";
}

sub WriteFile
{
    my ($file, $content) = @_;

    open (F, ">", $file) or die "$0: open $file $!";

    print F $content;

    close F;
}

sub ExitOnErrors
{
    return if $errors == 0;

    LogError "please correct all $errors error(s) before continue";

    exit 1;
}

sub Write
{
    my $content = shift;

    my $ident = ""; #GetIdent($content);

    my $line = $ident . $content . "\n";

    $line = "\n" if $content eq "";

    $SOURCE_CONTENT .= $line;
}

sub GetFunctionCamelCaseName
{
    my $fun = shift;

    $fun =~ s/^sai_//;

    my @tokens = split/_/,$fun;

    @tokens = map{ucfirst}@tokens;

    shift @tokens if $tokens[0] eq "api";

    $tokens[0] = lcfirst $tokens[0];

    $fun = join("",@tokens);

    return $fun;
}

sub GetData
{
    my $dir = shift;

    $DATA = `cat $dir/inc/sai*.h $dir/experimental/sai*.h`;
}

sub SanitizeData
{
    $DATA =~ s/SAI_OBJECT_TYPE_\w*(START|END|NULL|MAX)//gms;
    $DATA =~ s/SAI_API_\w*(START|END|UNSPECIFIED|MAX)//gms;
}

sub ExtractData
{
    @OBJECT_TYPES = $DATA =~ /^\s+SAI_OBJECT_TYPE\_(\w+)/gms;
    @APIS = $DATA =~ /^\s+SAI_API\_(\w+)/gms;

    for my $ot (@OBJECT_TYPES)
    {
        $objectTypes{lc$ot} = $ot;
    }

    @FUNCTIONS = $DATA =~ /(typedef sai_status_t \(\*(?:sai_\w+_fn)\).*?\))/gms;

    @globalApis = $DATA =~ /^((?:sai_\w+)\s+(?:sai_\w+).+?\))/gms;

    for my $fun (@FUNCTIONS)
    {
        next if not $fun =~ /sai_\w+\s+.*?(sai_\w+)/gms;

        $FUNCTIONS{$1} = $fun;
    }

    @apiStructs = $DATA =~ /(_sai_\w+_api_t.+?sai_\w+_api_t)/gms;

    for my $struct (@apiStructs)
    {
        next if not $struct =~ /sai_(\w+)_api_t/;

        $apiStructs{$1} = $struct;
    }
}

sub Entry
{
    my $i = shift;
    $i =~ s/entries/entry/;
    return $i;
}

sub GetFunctionName
{
    my $fun = shift;

    my $OT = "";
    my $bulk = 0;
    my $entry = 0;
    
    if ($fun =~ /(get|clear)_(\w+)_(stats(_ext)?)/ and defined $objectTypes{$2})
    {
        $OT = $objectTypes{$2};
        $fun = "$1_$3";
    }
    elsif ($fun =~ /(create|remove|set|get)_(\w+_entries)/ and defined $objectTypes{Entry($2)})
    {
        $bulk = 1;
        $OT = $objectTypes{Entry($2)};
        $fun = "bulk_$1";
    }
    elsif ($fun =~ /(set|get)_(\w+)s_attribute/ and defined $objectTypes{$2})
    {
        $bulk = 1;
        $OT = $objectTypes{$2};
        $fun = "bulk_$1";
    }
    elsif ($fun =~ /(set|get)_(\w+)_attribute/ and defined $objectTypes{$2})
    {
        $OT = $objectTypes{$2};
        $fun = "$1";
    }
    elsif ($fun =~ /(create|remove|set|get)_(\w+)s(_attribute)?/ and defined $objectTypes{$2})
    {
        $bulk = 1;
        $OT = $objectTypes{$2};
        $fun = "bulk_$1";
    }
    elsif ($fun =~ /(create|remove|set|get)_(\w+)(_attribute)?/ and defined $objectTypes{$2})
    {
        $OT = $objectTypes{$2};
        $fun = "$1";
    }
    elsif ($fun =~ /(create|remove|set|get)_(\w+)(_attribute)?/ and defined $objectTypes{$2})
    {
        $OT = $objectTypes{$2};
        $fun = $1; 
    }
    else
    {
        LogInfo "Unique function $fun";
    }

    $entry = 1 if $OT =~ /_ENTRY/;

    my $f = GetFunctionCamelCaseName($fun);

    # TODO figure this out
    $entry = 0 if $OT eq "ACL_ENTRY";
    $entry = 0 if $OT eq "HOSTIF_TABLE_ENTRY";
    $entry = 0 if $OT eq "TUNNEL_TERM_TABLE_ENTRY";
    $entry = 0 if $OT eq "TUNNEL_MAP_ENTRY";
    $entry = 0 if $OT eq "TABLE_BITMAP_CLASSIFICATION_ENTRY";
    $entry = 0 if $OT eq "TABLE_BITMAP_ROUTER_ENTRY";
    $entry = 0 if $OT eq "TABLE_META_TUNNEL_ENTRY";

    #LogInfo "$bulk $entry $fun $f $OT";

    return ($OT, $f, $entry, $bulk);
}

sub CreateApiStricts()
{
    Write "";
    Write "/* ==== API STRUCTS === */";
    Write "";

    for my $API (@APIS)
    {
        my $api = lc $API;

        Write "";
        Write "/* SAI APIS for $API */";
        Write "";

        my $struct = $apiStructs{$api};

        if (not defined $struct)
        {
            LogError "api $api not found";
            next;
        }

        while ($struct =~ /(sai_\w+_fn)\s+(\w+)/gms)
        {
            my $type = $1;
            my $funname = $2;

            my $fun = $FUNCTIONS{$type};

            if (not defined $fun)
            {
                LogError "function $fun not found";
                next;
            }

            next if not $fun =~ /(sai_\w+).+\((.+?)\)/gms;

            my $rettype = $1;
            my $params = $2;
            my @par = $params =~ /(\w+,|\w+$)/gms;

            my ($OT, $fname, $entry, $bulk) = GetFunctionName($funname);

            # TODO special case - switch 

            $par[0] = "switch_id,SAI_NULL_OBJECT_ID," if $OT eq "SWITCH" and $bulk == 0 and $fname eq "create";

            Write "static $rettype ${VAR}_$funname($params)";
            Write "{";
            Write "    SWSS_LOG_ENTER();";
            Write "";

            if ($fname =~ /(clearPortAllStats|removeAllNeighborEntries|recvHostifPacket|sendHostifPacket|allocateHostifPacket|freeHostifPacket)/)
            {
                Write "    SWSS_LOG_ERROR(\"FixME please, no implementation for $fname!\");";
                Write "    return SAI_STATUS_NOT_IMPLEMENTED;";
                Write "}";
                next;
            }

            Write "    return $VAR" . "->$fname(@par);" if $OT eq "";
            Write "    return $VAR" . "->$fname(@par);" if $OT ne "" and $bulk == 1 and $entry == 1;
            Write "    return $VAR" . "->$fname(@par);" if $OT ne "" and $bulk == 0 and $entry == 1;
            Write "    return $VAR" . "->$fname((sai_object_type_t)(SAI_OBJECT_TYPE_$OT),@par);" if $OT ne "" and $bulk == 0 and $entry == 0;
            Write "    return $VAR" . "->$fname((sai_object_type_t)(SAI_OBJECT_TYPE_$OT),@par);" if $OT ne "" and $bulk == 1 and $entry == 0;
            Write "}";
            Write "";
        }

        Write "const sai_${api}_api_t ${VAR}_${api} = {";

        while ($struct =~ /(sai_\w+_fn)\s+(\w+)/gms)
        {
            my $type = $1;
            my $funname = $2;

            Write "    .$funname = ${VAR}_$funname,";
        }

        Write "};";
        Write "";
    }
}

sub CreateHeader
{
    Write "";
    Write "/* DO NOT MODIFY, FILE AUTO GENERATED */";
    Write "";
    Write "extern \"C\" {";
    Write "#include \"sai.h\"";
    Write "#include \"saiextensions.h\"";
    Write "}";
    Write "#include \"meta/SaiInterface.h\"";
    Write "#include \"$CLASS.h\"";
    Write "#include \"swss/logger.h\"";
    Write "#include <memory>";
    Write "";
    Write "static std::shared_ptr<sairedis::SaiInterface> $VAR = std::make_shared<$NS" . "::$CLASS>();";
    Write ""
}

sub CreateApiStruct
{
    Write "";
    Write "/* ==== API STRUCTS === */";
    Write "";

    Write "static sai_apis_t ${VAR}_apis = {";

    for my $API (@APIS)
    {
        my $api = lc $API;

        Write "    .${api}_api = const_cast<sai_${api}_api_t*>(&${VAR}_${api}),";
    }

    Write "};";
    Write "";
}

sub CreateApiQuery
{
    Write "";
    Write "/* ==== API QUERY === */";
    Write "";

    Write "static_assert((sizeof(sai_apis_t)/sizeof(void*)) == (SAI_API_EXTENSIONS_MAX - 1));";
    Write "";
    Write "sai_status_t sai_api_query(";
    Write "        _In_ sai_api_t sai_api_id,";
    Write "        _Out_ void** api_method_table)";
    Write "{";
    Write "    SWSS_LOG_ENTER();";
    Write "";
    Write "    if (api_method_table == NULL)";
    Write "    {";
    Write "        SWSS_LOG_ERROR(\"NULL method table passed to SAI API initialize\");";
    Write "";
    Write "        return SAI_STATUS_INVALID_PARAMETER;";
    Write "    }";
    Write "";
    Write "    if (sai_api_id == SAI_API_UNSPECIFIED)";
    Write "    {";
    Write "        SWSS_LOG_ERROR(\"api ID is unspecified api\");";
    Write "";
    Write "        return SAI_STATUS_INVALID_PARAMETER;";
    Write "    }";
    Write "";
    Write "    if (sai_metadata_get_enum_value_name(&sai_metadata_enum_sai_api_t, sai_api_id))";
    Write "    {";
    Write "        *api_method_table = ((void**)&${VAR}_apis)[sai_api_id - 1];";
    Write "";
    Write "        return SAI_STATUS_SUCCESS;";
    Write "    }";
    Write "";
    Write "    SWSS_LOG_ERROR(\"Invalid API type %d\", sai_api_id);";
    Write "";
    Write "    return SAI_STATUS_INVALID_PARAMETER;";
    Write "}";
    Write "";
}

sub CreateGlobalApis
{
    Write "";
    Write "/* ==== GLOBAL APIS === */";
    Write "";

    for my $api (sort @globalApis)
    {
        next if not $api =~ /(sai_\w+)\s+(sai_\w+).*\((.+?)\)/gms;

        my $rettype = $1;
        my $funname = $2;
        my $params = $3;

        next if $funname eq "sai_api_query";

        my @par = $params =~ /(\w+,|\w+$)/gms;

        $funname =~ s/^sai_api_//;

        my $fun = GetFunctionCamelCaseName($funname);

        $par[0] = "" if $par[0] eq "void";

        Write "$rettype $funname($params)";
        Write "{";
        Write "    SWSS_LOG_ENTER();";
        Write "";

        if ($fun =~ /(bulkObjectClearStats|bulkObjectGetStats|dbgGenerateDump|getMaximumAttributeCount|getObjectKey|bulkGetAttribute|dbgGenerateDump|tamTelemetryGetData|getObjectCount|queryAttributeEnumValuesCapability|queryObjectStage)/)
        {
            Write "    SWSS_LOG_ERROR(\"FixME please, no implementation for $fun!\");";
            Write "    return SAI_STATUS_NOT_IMPLEMENTED;";
            Write "}";
            next;
        }

        Write "    return $VAR" . "->$fun(@par);";
        Write "}";
        Write "";
    }
}

#
# MAIN
#

GetData($optionSaiDir);
SanitizeData();
ExtractData();
CreateHeader();
CreateApiStricts();
CreateApiStruct();
CreateApiQuery();
CreateGlobalApis();
ExitOnErrors();
WriteFile($FILE,$SOURCE_CONTENT);
