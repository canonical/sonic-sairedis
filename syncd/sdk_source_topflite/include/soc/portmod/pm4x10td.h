/*
 *         
 * $Id:$
 * 
 * $Copyright: (c) 2020 Broadcom.
 * Broadcom Proprietary and Confidential. All rights reserved.$
 *         
 *     
 * DO NOT EDIT THIS FILE!
 *
 */

#ifndef _PM4X10TD_H__H_
#define _PM4X10TD_H__H_

#include <phymod/phymod.h>
#include <phymod/phymod_diagnostics.h>
#include <phymod/phymod_reg.h>
#include <soc/cprimod/cprimod.h>
#include <soc/portmod/portmod_defs.h>
#include <sal/core/sync.h>
/*set PFC config registers.*/
int pm4x10td_port_pfc_config_set(int unit, int port, pm_info_t pm_info, const portmod_pfc_config_t* pfc_cfg);
int pm4x10td_port_pfc_config_get(int unit, int port, pm_info_t pm_info, portmod_pfc_config_t* pfc_cfg);

/*Disable lag failover.*/
int pm4x10td_port_cntmaxsize_set(int unit, int port, pm_info_t pm_info, int val);
int pm4x10td_port_cntmaxsize_get(int unit, int port, pm_info_t pm_info, int* val);

/* portmod port rsv mask set*/
int pm4x10td_port_mac_rsv_mask_set(int unit, int port, pm_info_t pm_info, uint32 rsv_mask);

/* portmod port mib reset toggle*/
int pm4x10td_port_mib_reset_toggle(int unit, int port, pm_info_t pm_info, int port_index);

#endif /*_PM4X10TD_H_*/
