#pragma once

#include "swss/sal.h"

#include <string>
#include <vector>

namespace saiplayer
{
    class CommandLineOptions
    {
        public:

            CommandLineOptions();

            virtual ~CommandLineOptions() = default;

        public:

            virtual std::string getCommandLineString() const;

        public:

            bool m_useTempView;

            bool m_inspectAsic;

            bool m_skipNotifySyncd;

            bool m_enableDebug;

            bool m_sleep;

            bool m_syncMode;

            bool m_zmqSyncMode;

            bool m_enableRecording;

            std::string m_profileMapFile;

            std::string m_contextConfig;

            std::vector<std::string> m_files;
    };
}
