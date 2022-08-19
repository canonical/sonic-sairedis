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

#ifndef _PM8X50_H__H_
#define _PM8X50_H__H_

#include <phymod/phymod.h>
#include <phymod/phymod_diagnostics.h>
#include <phymod/phymod_reg.h>
#include <soc/cprimod/cprimod.h>
#include <soc/portmod/portmod_defs.h>
#include <sal/core/sync.h>
/**/
int pm8x50_port_speed_ability_local_get(int unit, int port, pm_info_t pm_info, int max_num_abilities, portmod_port_speed_ability_t* abilities, int* num_abilities);

/*Get whether the inerface type is supported by PM */
int pm8x50_pm_interface_type_is_supported(int unit, soc_port_if_t interface, int* is_supported);

/*Add new pm.*/
int pm8x50_pm_init(int unit, const portmod_pm_create_info_internal_t* pm_add_info, int wb_buffer_index, pm_info_t pm_info);

/*Release PM resources*/
int pm8x50_pm_destroy(int unit, pm_info_t pm_info);

/*Add new port*/
int pm8x50_port_attach(int unit, int port, pm_info_t pm_info, const portmod_port_add_info_t* add_info);

/*get port cores' phymod access*/
int pm8x50_pm_core_info_get(int unit, pm_info_t pm_info, int phyn, portmod_pm_core_info_t* core_info);

/*Get PM phys.*/
int pm8x50_pm_phys_get(int unit, pm_info_t pm_info, portmod_pbmp_t* phys);

/*Port remove in PM level*/
int pm8x50_port_detach(int unit, int port, pm_info_t pm_info);

/*Unregister the callback function and clear the some state*/
int pm8x50_port_callback_unregister(int unit, int port, pm_info_t pm_info);

/*Port replace in PM level*/
int pm8x50_port_replace(int unit, int port, pm_info_t pm_info, int new_port);

/*Port enable*/
int pm8x50_port_enable_set(int unit, int port, pm_info_t pm_info, int flags, int enable);
int pm8x50_port_enable_get(int unit, int port, pm_info_t pm_info, int flags, int* enable);

/*Port cl72 set\get*/
int pm8x50_port_cl72_set(int unit, int port, pm_info_t pm_info, uint32 enable);
int pm8x50_port_cl72_get(int unit, int port, pm_info_t pm_info, uint32* enable);

/*Get port cl72 status*/
int pm8x50_port_cl72_status_get(int unit, int port, pm_info_t pm_info, phymod_cl72_status_t* status);

/*Port speed set\get*/
int pm8x50_port_loopback_set(int unit, int port, pm_info_t pm_info, portmod_loopback_mode_t loopback_type, int enable);
int pm8x50_port_loopback_get(int unit, int port, pm_info_t pm_info, portmod_loopback_mode_t loopback_type, int* enable);

/*Port RX MAC ENABLE set\get*/
int pm8x50_port_rx_mac_enable_set(int unit, int port, pm_info_t pm_info, int enable);
int pm8x50_port_rx_mac_enable_get(int unit, int port, pm_info_t pm_info, int* enable);

/*Port TX MAC ENABLE set\get*/
int pm8x50_port_tx_mac_enable_set(int unit, int port, pm_info_t pm_info, int enable);
int pm8x50_port_tx_mac_enable_get(int unit, int port, pm_info_t pm_info, int* enable);

/*Set\Get autoneg*/
int pm8x50_port_autoneg_set(int unit, int port, pm_info_t pm_info, uint32 phy_flags, const phymod_autoneg_control_t* an);
int pm8x50_port_autoneg_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, phymod_autoneg_control_t* an);

/*Get autoneg status*/
int pm8x50_port_autoneg_status_get(int unit, int port, pm_info_t pm_info, phymod_autoneg_status_t* an_status);

/*get link status*/
int pm8x50_port_link_get(int unit, int port, pm_info_t pm_info, int flags, int* link);

/*get latch down link status (whether link was ever down since last clear)*/
int pm8x50_port_link_latch_down_get(int unit, int port, pm_info_t pm_info, uint32 flags, int* link);

/* link up event */
int pm8x50_port_phy_link_up_event(int unit, int port, pm_info_t pm_info);

/* link down event */
int pm8x50_port_phy_link_down_event(int unit, int port, pm_info_t pm_info);

/*PRBS configuration set/get*/
int pm8x50_port_prbs_config_set(int unit, int port, pm_info_t pm_info, portmod_prbs_mode_t mode, int flags, const phymod_prbs_t* config);
int pm8x50_port_prbs_config_get(int unit, int port, pm_info_t pm_info, portmod_prbs_mode_t mode, int flags, phymod_prbs_t* config);

/*PRBS enable set/get*/
int pm8x50_port_prbs_enable_set(int unit, int port, pm_info_t pm_info, portmod_prbs_mode_t mode, int flags, int enable);
int pm8x50_port_prbs_enable_get(int unit, int port, pm_info_t pm_info, portmod_prbs_mode_t mode, int flags, int* enable);

/*PRBS status get*/
int pm8x50_port_prbs_status_get(int unit, int port, pm_info_t pm_info, portmod_prbs_mode_t mode, int flags, phymod_prbs_status_t* status);

/*Number of lanes get*/
int pm8x50_port_nof_lanes_get(int unit, int port, pm_info_t pm_info, int* nof_lanes);

/*Set port PHYs' firmware mode*/
int pm8x50_port_firmware_mode_set(int unit, int port, pm_info_t pm_info, phymod_firmware_mode_t fw_mode);
int pm8x50_port_firmware_mode_get(int unit, int port, pm_info_t pm_info, phymod_firmware_mode_t* fw_mode);

/*Filter packets smaller than the specified threshold*/
int pm8x50_port_runt_threshold_set(int unit, int port, pm_info_t pm_info, int value);
int pm8x50_port_runt_threshold_get(int unit, int port, pm_info_t pm_info, int* value);

/*Filter packets bigger than the specified value*/
int pm8x50_port_max_packet_size_set(int unit, int port, pm_info_t pm_info, int value);
int pm8x50_port_max_packet_size_get(int unit, int port, pm_info_t pm_info, int* value);

/*TX pad packets to the specified size. values smaller than 17 means pad is disabled.*/
int pm8x50_port_pad_size_set(int unit, int port, pm_info_t pm_info, int value);
int pm8x50_port_pad_size_get(int unit, int port, pm_info_t pm_info, int* value);

/*set/get the MAC source address that will be sent in case of Pause/LLFC*/
int pm8x50_port_tx_mac_sa_set(int unit, int port, pm_info_t pm_info, sal_mac_addr_t mac_sa);
int pm8x50_port_tx_mac_sa_get(int unit, int port, pm_info_t pm_info, sal_mac_addr_t mac_sa);

/*set/get SA recognized for MAC control packets in addition to the standard 0x0180C2000001*/
int pm8x50_port_rx_mac_sa_set(int unit, int port, pm_info_t pm_info, sal_mac_addr_t mac_sa);
int pm8x50_port_rx_mac_sa_get(int unit, int port, pm_info_t pm_info, sal_mac_addr_t mac_sa);

/*set/get Average inter-packet gap*/
int pm8x50_port_tx_average_ipg_set(int unit, int port, pm_info_t pm_info, int value);
int pm8x50_port_tx_average_ipg_get(int unit, int port, pm_info_t pm_info, int* value);

/*local fault set/get*/
int pm8x50_port_local_fault_control_set(int unit, int port, pm_info_t pm_info, const portmod_local_fault_control_t* control);
int pm8x50_port_local_fault_control_get(int unit, int port, pm_info_t pm_info, portmod_local_fault_control_t* control);

/*remote fault set/get*/
int pm8x50_port_remote_fault_control_set(int unit, int port, pm_info_t pm_info, const portmod_remote_fault_control_t* control);
int pm8x50_port_remote_fault_control_get(int unit, int port, pm_info_t pm_info, portmod_remote_fault_control_t* control);

/*local fault steatus get*/
int pm8x50_port_local_fault_status_get(int unit, int port, pm_info_t pm_info, int* value);

/*remote fault status get*/
int pm8x50_port_remote_fault_status_get(int unit, int port, pm_info_t pm_info, int* value);

/*local fault steatus clear*/
int pm8x50_port_local_fault_status_clear(int unit, int port, pm_info_t pm_info);

/*remote fault status clear*/
int pm8x50_port_remote_fault_status_clear(int unit, int port, pm_info_t pm_info);

/*local fault reasons get*/
int pm8x50_port_local_fault_reasons_get(int unit, int port, pm_info_t pm_info, uint32* local_fault_reasons);

/*set/get Pause FC configuration*/
int pm8x50_port_pause_control_set(int unit, int port, pm_info_t pm_info, const portmod_pause_control_t* control);
int pm8x50_port_pause_control_get(int unit, int port, pm_info_t pm_info, portmod_pause_control_t* control);

/*set/get PFC FC configuration*/
int pm8x50_port_pfc_control_set(int unit, int port, pm_info_t pm_info, const portmod_pfc_control_t* control);
int pm8x50_port_pfc_control_get(int unit, int port, pm_info_t pm_info, portmod_pfc_control_t* control);

/*Routine for MAC\PHY sync.*/
int pm8x50_port_update(int unit, int port, pm_info_t pm_info, const portmod_port_update_control_t* update_control);

/*get port cores' phymod access*/
int pm8x50_port_core_access_get(int unit, int port, pm_info_t pm_info, int phyn, int max_cores, phymod_core_access_t* core_access_arr, int* nof_cores, int* is_most_ext);

/*Get lane phymod access structure. can be used for per lane operations*/
int pm8x50_port_phy_lane_access_get(int unit, int port, pm_info_t pm_info, const portmod_access_get_params_t* params, int max_phys, phymod_phy_access_t* access, int* nof_phys, int* is_most_ext);

/*Get lane phymod access structure via pm id. Should be used only when there is no port attached */
int pm8x50_pm_phy_lane_access_get(int unit, int pm_id, pm_info_t pm_info, const portmod_access_get_params_t* params, int max_phys, phymod_phy_access_t* access, int* nof_phys, int* is_most_ext);

/*Port duplex set\get*/
int pm8x50_port_duplex_set(int unit, int port, pm_info_t pm_info, int enable);
int pm8x50_port_duplex_get(int unit, int port, pm_info_t pm_info, int* enable);

/*Port PHY Control register read*/
int pm8x50_port_phy_reg_read(int unit, int port, pm_info_t pm_info, int lane, int flags, int reg_addr, uint32* value);

/*Port PHY Control register write*/
int pm8x50_port_phy_reg_write(int unit, int port, pm_info_t pm_info, int lane, int flags, int reg_addr, uint32 value);

/*Port Reset set\get*/
int pm8x50_port_reset_set(int unit, int port, pm_info_t pm_info, int mode, int opcode, int value);
int pm8x50_port_reset_get(int unit, int port, pm_info_t pm_info, int mode, int opcode, int* value);

/*Drv Name Get*/
int pm8x50_port_drv_name_get(int unit, int port, pm_info_t pm_info, char* name, int len);

/*set/get port fec enable according to local/remote FEC ability*/
int pm8x50_port_fec_enable_set(int unit, int port, pm_info_t pm_info, uint32 phy_flags, uint32_t enable);
int pm8x50_port_fec_enable_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, uint32_t* enable);

/*get port auto negotiation local ability*/
int pm8x50_port_ability_advert_set(int unit, int port, pm_info_t pm_info, uint32 phy_flags, portmod_port_ability_t* ability);
int pm8x50_port_ability_advert_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, portmod_port_ability_t* ability);

/*Port ability remote Adv get*/
int pm8x50_port_ability_remote_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, portmod_port_ability_t* ability);

/*Port Mac Control Spacing Stretch*/
int pm8x50_port_frame_spacing_stretch_set(int unit, int port, pm_info_t pm_info, int spacing);
int pm8x50_port_frame_spacing_stretch_get(int unit, int port, pm_info_t pm_info, const int* spacing);

/*get port timestamps in fifo*/
int pm8x50_port_diag_fifo_status_get(int unit, int port, pm_info_t pm_info, const portmod_fifo_status_t* diag_info);

/*set/get pass control frames.*/
int pm8x50_port_rx_control_set(int unit, int port, pm_info_t pm_info, const portmod_rx_control_t* rx_ctrl);
int pm8x50_port_rx_control_get(int unit, int port, pm_info_t pm_info, portmod_rx_control_t* rx_ctrl);

/*set PFC config registers.*/
int pm8x50_port_pfc_config_set(int unit, int port, pm_info_t pm_info, const portmod_pfc_config_t* pfc_cfg);
int pm8x50_port_pfc_config_get(int unit, int port, pm_info_t pm_info, portmod_pfc_config_t* pfc_cfg);

/*set EEE Config.*/
int pm8x50_port_eee_set(int unit, int port, pm_info_t pm_info, const portmod_eee_t* eee);
int pm8x50_port_eee_get(int unit, int port, pm_info_t pm_info, portmod_eee_t* eee);

/*set EEE Config.*/
int pm8x50_port_eee_clock_set(int unit, int port, pm_info_t pm_info, const portmod_eee_clock_t* eee_clk);
int pm8x50_port_eee_clock_get(int unit, int port, pm_info_t pm_info, portmod_eee_clock_t* eee_clk);

/*set Vlan Inner/Outer tag.*/
int pm8x50_port_vlan_tag_set(int unit, int port, pm_info_t pm_info, const portmod_vlan_tag_t* vlan_tag);
int pm8x50_port_vlan_tag_get(int unit, int port, pm_info_t pm_info, portmod_vlan_tag_t* vlan_tag);

/*set modid field.*/
int pm8x50_port_modid_set(int unit, int port, pm_info_t pm_info, int value);

/*set modid field.*/
int pm8x50_port_led_chain_config(int unit, int port, pm_info_t pm_info, int value);

/*set modid field.*/
int pm8x50_port_clear_rx_lss_status_set(int unit, int port, pm_info_t pm_info, int lcl_fault, int rmt_fault);
int pm8x50_port_clear_rx_lss_status_get(int unit, int port, pm_info_t pm_info, int* lcl_fault, int* rmt_fault);

/*Attaches an external phy lane to a specific port macro*/
int pm8x50_xphy_lane_attach_to_pm(int unit, pm_info_t pm_info, int iphy, int phyn, const portmod_xphy_lane_connection_t* lane_connection);

/*Attaches an external phy lane to a specific port macro*/
int pm8x50_xphy_lane_detach_from_pm(int unit, pm_info_t pm_info, int iphy, int phyn, portmod_xphy_lane_connection_t* lane_connection);

/*Toggle Lag Failover Status.*/
int pm8x50_port_lag_failover_status_toggle(int unit, int port, pm_info_t pm_info);

/*Toggle Lag Failover loopback set / get.*/
int pm8x50_port_lag_failover_loopback_set(int unit, int port, pm_info_t pm_info, int value);
int pm8x50_port_lag_failover_loopback_get(int unit, int port, pm_info_t pm_info, int* value);

/*set port mode.*/
int pm8x50_port_mode_set(int unit, int port, pm_info_t pm_info, const portmod_port_mode_info_t* mode);
int pm8x50_port_mode_get(int unit, int port, pm_info_t pm_info, portmod_port_mode_info_t* mode);

/*set port encap.*/
int pm8x50_port_encap_set(int unit, int port, pm_info_t pm_info, int flags, portmod_encap_t encap);
int pm8x50_port_encap_get(int unit, int port, pm_info_t pm_info, int* flags, portmod_encap_t* encap);

/*set port register higig field.*/
int pm8x50_port_higig_mode_set(int unit, int port, pm_info_t pm_info, int mode);
int pm8x50_port_higig_mode_get(int unit, int port, pm_info_t pm_info, int* mode);

/*set port register higig field.*/
int pm8x50_port_higig2_mode_set(int unit, int port, pm_info_t pm_info, int mode);
int pm8x50_port_higig2_mode_get(int unit, int port, pm_info_t pm_info, int* mode);

/*set port register port type field.*/
int pm8x50_port_config_port_type_set(int unit, int port, pm_info_t pm_info, int type);
int pm8x50_port_config_port_type_get(int unit, int port, pm_info_t pm_info, int* type);

/*set/get hwfailover for trident.*/
int pm8x50_port_trunk_hwfailover_config_set(int unit, int port, pm_info_t pm_info, int hw_count);
int pm8x50_port_trunk_hwfailover_config_get(int unit, int port, pm_info_t pm_info, int* enable);

/*set/get hwfailover for trident.*/
int pm8x50_port_trunk_hwfailover_status_get(int unit, int port, pm_info_t pm_info, int* loopback);

/*port diagnostics control.*/
int pm8x50_port_diag_ctrl(int unit, int port, pm_info_t pm_info, uint32 inst, int op_type, int op_cmd, const void* arg);

/*Get the reference clock value 156 or 125.*/
int pm8x50_port_ref_clk_get(int unit, int port, pm_info_t pm_info, int* ref_clk);

/*Disable lag failover.*/
int pm8x50_port_lag_failover_disable(int unit, int port, pm_info_t pm_info);

/*Disable lag failover.*/
int pm8x50_port_lag_remove_failover_lpbk_set(int unit, int port, pm_info_t pm_info, int val);
int pm8x50_port_lag_remove_failover_lpbk_get(int unit, int port, pm_info_t pm_info, int* val);

/*Disable lag failover.*/
int pm8x50_port_cntmaxsize_set(int unit, int port, pm_info_t pm_info, int val);
int pm8x50_port_cntmaxsize_get(int unit, int port, pm_info_t pm_info, int* val);

/*Get Info needed to restore after drain cells.*/
int pm8x50_port_drain_cell_get(int unit, int port, pm_info_t pm_info, portmod_drain_cells_t* drain_cells);

/*Restore informaation after drain cells.*/
int pm8x50_port_drain_cell_stop(int unit, int port, pm_info_t pm_info, const portmod_drain_cells_t* drain_cells);

/*Restore informaation after drain cells.*/
int pm8x50_port_drain_cell_start(int unit, int port, pm_info_t pm_info);

/**/
int pm8x50_port_drain_cells_rx_enable(int unit, int port, pm_info_t pm_info, int rx_en);

/**/
int pm8x50_port_egress_queue_drain_rx_en(int unit, int port, pm_info_t pm_info, int rx_en);

/**/
int pm8x50_port_mac_ctrl_set(int unit, int port, pm_info_t pm_info, uint64 ctrl);

/**/
int pm8x50_port_txfifo_cell_cnt_get(int unit, int port, pm_info_t pm_info, uint32* cnt);

/**/
int pm8x50_port_egress_queue_drain_get(int unit, int port, pm_info_t pm_info, uint64* ctrl, int* rxen);

/*Set/get port mac reset */
int pm8x50_port_mac_reset_set(int unit, int port, pm_info_t pm_info, int val);
int pm8x50_port_mac_reset_get(int unit, int port, pm_info_t pm_info, int* val);

/**/
int pm8x50_port_soft_reset_toggle(int unit, int port, pm_info_t pm_info, int idx);

/**/
int pm8x50_port_soft_reset(int unit, int port, pm_info_t pm_info, portmod_mac_soft_reset_mode_t reset_mode, int* saved_rx_enable, uint64* saved_mac_ctrl);

/*Check if MAC needs to be reset.*/
int pm8x50_port_mac_reset_check(int unit, int port, pm_info_t pm_info, int enable, int* reset);

/**/
int pm8x50_port_core_num_get(int unit, int port, pm_info_t pm_info, int* core_num);

/**/
int pm8x50_port_e2ecc_hdr_set(int unit, int port, pm_info_t pm_info, const portmod_port_higig_e2ecc_hdr_t* e2ecc_hdr);
int pm8x50_port_e2ecc_hdr_get(int unit, int port, pm_info_t pm_info, portmod_port_higig_e2ecc_hdr_t* e2ecc_hdr);

/**/
int pm8x50_port_e2e_enable_set(int unit, int port, pm_info_t pm_info, int enable);
int pm8x50_port_e2e_enable_get(int unit, int port, pm_info_t pm_info, int* enable);

/*get the speed for the specified port*/
int pm8x50_port_speed_get(int unit, int port, pm_info_t pm_info, int* speed);

/*Port discard set*/
int pm8x50_port_discard_set(int unit, int port, pm_info_t pm_info, int discard);

/*Port soft reset set set*/
int pm8x50_port_soft_reset_set(int unit, int port, pm_info_t pm_info, int idx, int val, int flags);

/*Port tx_en=0 and softreset mac*/
int pm8x50_port_tx_down(int unit, int port, pm_info_t pm_info);

/*reconfig pgw.*/
int pm8x50_port_pgw_reconfig(int unit, int port, pm_info_t pm_info, const portmod_port_mode_info_t* pmode, int phy_port, int flags);

/*Routine to notify internal phy of external phy link state.*/
int pm8x50_port_notify(int unit, int port, pm_info_t pm_info, int link);

/*"port control phy timesync config set/get"*/
int pm8x50_port_control_phy_timesync_set(int unit, int port, pm_info_t pm_info, portmod_port_control_phy_timesync_t config, uint64 value);
int pm8x50_port_control_phy_timesync_get(int unit, int port, pm_info_t pm_info, portmod_port_control_phy_timesync_t config, uint64* value);

/*"port timesync config set/get"*/
int pm8x50_port_timesync_config_set(int unit, int port, pm_info_t pm_info, const portmod_phy_timesync_config_t* config);
int pm8x50_port_timesync_config_get(int unit, int port, pm_info_t pm_info, portmod_phy_timesync_config_t* config);

/*"port timesync enable set/get"*/
int pm8x50_port_timesync_enable_set(int unit, int port, pm_info_t pm_info, uint32 enable);
int pm8x50_port_timesync_enable_get(int unit, int port, pm_info_t pm_info, uint32* enable);

/*"port timesync nco addend  set/get"*/
int pm8x50_port_timesync_nco_addend_set(int unit, int port, pm_info_t pm_info, uint32 freq_step);
int pm8x50_port_timesync_nco_addend_get(int unit, int port, pm_info_t pm_info, uint32* freq_step);

/*"port timesync framesync info  set/get"*/
int pm8x50_port_timesync_framesync_mode_set(int unit, int port, pm_info_t pm_info, const portmod_timesync_framesync_t* framesync);
int pm8x50_port_timesync_framesync_mode_get(int unit, int port, pm_info_t pm_info, portmod_timesync_framesync_t* framesync);

/*"port timesync local time  set/get"*/
int pm8x50_port_timesync_local_time_set(int unit, int port, pm_info_t pm_info, uint64 local_time);
int pm8x50_port_timesync_local_time_get(int unit, int port, pm_info_t pm_info, uint64* local_time);

/*"port timesync framesync info  set/get"*/
int pm8x50_port_timesync_load_ctrl_set(int unit, int port, pm_info_t pm_info, uint32 load_once, uint32 load_always);
int pm8x50_port_timesync_load_ctrl_get(int unit, int port, pm_info_t pm_info, uint32* load_once, uint32* load_always);

/*"port timesync tx timestamp offset set/get"*/
int pm8x50_port_timesync_tx_timestamp_offset_set(int unit, int port, pm_info_t pm_info, uint32 ts_offset);
int pm8x50_port_timesync_tx_timestamp_offset_get(int unit, int port, pm_info_t pm_info, uint32* ts_offset);

/*"port timesync rx timestamp offset set/get"*/
int pm8x50_port_timesync_rx_timestamp_offset_set(int unit, int port, pm_info_t pm_info, uint32 ts_offset);
int pm8x50_port_timesync_rx_timestamp_offset_get(int unit, int port, pm_info_t pm_info, uint32* ts_offset);

/*set/get interrupt enable value. */
int pm8x50_port_interrupt_enable_set(int unit, int port, pm_info_t pm_info, int intr_type, uint32 val);
int pm8x50_port_interrupt_enable_get(int unit, int port, pm_info_t pm_info, int intr_type, uint32* val);

/*get interrupt status value. */
int pm8x50_port_interrupt_get(int unit, int port, pm_info_t pm_info, int intr_type, uint32* val);

/*get interrupt value array. */
int pm8x50_port_interrupts_get(int unit, int port, pm_info_t pm_info, int arr_max_size, uint32* intr_arr, uint32* size);

/* portmod check if external phy is legacy*/
int pm8x50_port_check_legacy_phy(int unit, int port, pm_info_t pm_info, int* legacy_phy);

/* portmod phy failover mode*/
int pm8x50_port_failover_mode_set(int unit, int port, pm_info_t pm_info, phymod_failover_mode_t failover);
int pm8x50_port_failover_mode_get(int unit, int port, pm_info_t pm_info, phymod_failover_mode_t* failover);

/* portmod port rsv mask set*/
int pm8x50_port_mac_rsv_mask_set(int unit, int port, pm_info_t pm_info, uint32 rsv_mask);

/* portmod restore information after warmboot*/
int pm8x50_port_warmboot_db_restore(int unit, int port, pm_info_t pm_info, const portmod_port_interface_config_t* intf_config, const portmod_port_init_config_t* init_config, phymod_operation_mode_t phy_op_mode);

/* portmod port flow control config*/
int pm8x50_port_flow_control_set(int unit, int port, pm_info_t pm_info, int merge_mode_en, int parallel_fc_en);

/*Portmod state for any logical port dynamixc settings*/
int pm8x50_port_update_dynamic_state(int unit, int port, pm_info_t pm_info, uint32_t port_dynamic_state);

/*get phy operation mode. */
int pm8x50_port_phy_op_mode_get(int unit, int port, pm_info_t pm_info, phymod_operation_mode_t* val);

/*override function for board lane swap. */
int pm8x50_port_lane_map_set(int unit, int port, pm_info_t pm_info, uint32 flags, const phymod_lane_map_t* lane_map);
int pm8x50_port_lane_map_get(int unit, int port, pm_info_t pm_info, uint32 flags, phymod_lane_map_t* lane_map);

/*Get timestamp and sequence id of tx 1588 packet.*/
int pm8x50_port_timesync_tx_info_get(int unit, int port, pm_info_t pm_info, portmod_fifo_status_t* tx_info);

/*PM Core init routine for DNX devices; XGS does not call this API but calls portmod_pm_serdes_core_init() directly*/
int pm8x50_core_add(int unit, int pm_id, pm_info_t pm_info, int flags, const portmod_port_add_info_t* add_info);

/*PM Core init routine*/
int pm8x50_pm_serdes_core_init(int unit, int pm_id, pm_info_t pm_info, const portmod_port_add_info_t* add_info);

/*Returns if the PortMacro associated with the port is initialized or not*/
int pm8x50_pm_is_initialized(int unit, int pm_id, pm_info_t pm_info, int* is_initialized);

/*Port speed validation.*/
int pm8x50_port_speed_config_validate(int unit, int port, pm_info_t pm_info, const portmod_speed_config_t* speed_config, portmod_pbmp_t* affected_pbmp);

/*Enable port macro.*/
int pm8x50_pm_enable(int unit, int pm_id, pm_info_t pm_info, int flags, int enable);

/*Get the logical port bitmap based on the input PM ID*/
int pm8x50_pm_logical_pbmp_get(int unit, int pm_id, pm_info_t pm_info, portmod_pbmp_t* logical_pbmp);

/*Reconfigure the vco rate for pm core.*/
int pm8x50_pm_vco_reconfig(int unit, int pm_id, pm_info_t pm_info, const portmod_vco_type_t* vco);

/* set/get the speed config for the specified port.*/
int pm8x50_port_speed_config_set(int unit, int port, pm_info_t pm_info, const portmod_speed_config_t* speed_config);
int pm8x50_port_speed_config_get(int unit, int port, pm_info_t pm_info, portmod_speed_config_t* speed_config);

/*Validate a set of speed config within a port macro.*/
int pm8x50_pm_speed_config_validate(int unit, int pm_id, pm_info_t pm_info, const portmod_pbmp_t* ports, int flag, portmod_pm_vco_setting_t* vco_setting);

/*Get the suggested VCO values based on the speed config list of a PM*/
int pm8x50_pm_vcos_get(int unit, portmod_dispatch_type_t pm_type, uint32 flags, portmod_pm_vco_setting_t* vco_select);

/*Set/get port auto negotiation ability*/
int pm8x50_port_autoneg_ability_advert_set(int unit, int port, pm_info_t pm_info, int num_abilities, const portmod_port_speed_ability_t* abilities);
int pm8x50_port_autoneg_ability_advert_get(int unit, int port, pm_info_t pm_info, int max_num_abilities, portmod_port_speed_ability_t* abilities, int* actual_num_abilities);

/*Port ability remote Adv get*/
int pm8x50_port_autoneg_ability_remote_get(int unit, int port, pm_info_t pm_info, int max_num_abilities, portmod_port_speed_ability_t* abilities, int* actual_num_abilities);

/*Port tx taps set\get*/
int pm8x50_port_tx_set(int unit, int port, pm_info_t pm_info, const phymod_tx_t* tx);
int pm8x50_port_tx_get(int unit, int port, pm_info_t pm_info, phymod_tx_t* tx);

/*Port SyncE clock control config*/
int pm8x50_port_synce_clk_ctrl_set(int unit, int port, pm_info_t pm_info, const portmod_port_synce_clk_ctrl_t* cfg);
int pm8x50_port_synce_clk_ctrl_get(int unit, int port, pm_info_t pm_info, portmod_port_synce_clk_ctrl_t* cfg);

/*Process PM interrupts.*/
int pm8x50_pm_interrupt_process(int unit, int pm_id, pm_info_t pm_info, portmod_ecc_intr_info_t* ecc_err_info);

/**/
int pm8x50_pm_core_num_get(int unit, pm_info_t pm_info, int* core_num);

/*RLM config set */
int pm8x50_port_rlm_config_set(int unit, int port, pm_info_t pm_info, int enable, const portmod_port_rlm_config_t* rlm_config);

/*RLM status get */
int pm8x50_port_rlm_config_get(int unit, int port, pm_info_t pm_info, int* enable, portmod_port_rlm_config_t* rlm_status);

/*RLM status get */
int pm8x50_port_rlm_status_get(int unit, int port, pm_info_t pm_info, portmod_port_rlm_status_t* rlm_status);

/* Enable port MAC settings. This function sets MAC rx enable and soft reset.
                  This should only be invoked during fast reboot,
                  where the application layer do not wait to drain
                  the packets on a port and should not be called
                  during normal operation.*/
int pm8x50_port_mac_enable_set(int unit, int port, pm_info_t pm_info, int enable);

/*Set PM based EGR 1588 timestamping configuration.*/
int pm8x50_egr_1588_timestamp_config_set(int unit, int port, pm_info_t pm_info, portmod_egr_1588_timestamp_config_t timestamp_config);
int pm8x50_egr_1588_timestamp_config_get(int unit, int port, pm_info_t pm_info, portmod_egr_1588_timestamp_config_t* timestamp_config);

/*function for reconfig PCS lane swap. */
int pm8x50_port_pcs_lane_map_reconfig(int unit, int port, pm_info_t pm_info, uint32 tx_lane_swap, uint32 rx_lane_swap);

/* Get the sum of pmd_lock_counters of all the port's lanes */
int pm8x50_port_pmd_lock_counter_get(int unit, int port, pm_info_t pm_info, uint32* pmd_lock_counter_sum);

/* Debug logging of warmboot cached information for a given port macro. Needs boot flag BOOT_F_EARLY_DBG to be set.
            */
int pm8x50_pm_wb_debug_log(int unit, pm_info_t pm_info);

/*Control one time fec error injection.*/
int pm8x50_port_fec_error_inject_set(int unit, int port, pm_info_t pm_info, uint16 error_control_map, portmod_fec_error_mask_t bit_error_mask);
int pm8x50_port_fec_error_inject_get(int unit, int port, pm_info_t pm_info, uint16* error_control_map, portmod_fec_error_mask_t* bit_error_mask);

#endif /*_PM8X50_H_*/
