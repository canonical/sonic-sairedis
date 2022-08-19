/* $Id: $
 * 
 * $Copyright: (c) 2020 Broadcom.
 * Broadcom Proprietary and Confidential. All rights reserved.$
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 * search for 'sw_state_cbs_t' for the root of the struct
 */

#ifndef _SHR_SW_STATE_DPP_BCM_TRILL_ACCESS_H_
#define _SHR_SW_STATE_DPP_BCM_TRILL_ACCESS_H_

/********************************* access calbacks definitions *************************************/
/* this set of callbacks, are the callbacks used in the access calbacks struct 'sw_state_cbs_t' to */
/* access the data in 'sw_state_t'.                                                                */
/* the calbacks are inserted into the access struct by 'sw_state_access_cb_init'.                  */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_alloc */
typedef int (*sw_state_dpp_bcm_trill_alloc_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_is_allocated */
typedef int (*sw_state_dpp_bcm_trill_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_free */
typedef int (*sw_state_dpp_bcm_trill_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_verify */
typedef int (*sw_state_dpp_bcm_trill_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_init_set */
typedef int (*sw_state_dpp_bcm_trill_init_set_cb)(
    int unit, int init);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_init_get */
typedef int (*sw_state_dpp_bcm_trill_init_get_cb)(
    int unit, int *init);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_init_verify */
typedef int (*sw_state_dpp_bcm_trill_init_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mask_set_set */
typedef int (*sw_state_dpp_bcm_trill_mask_set_set_cb)(
    int unit, int mask_set);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mask_set_get */
typedef int (*sw_state_dpp_bcm_trill_mask_set_get_cb)(
    int unit, int *mask_set);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mask_set_verify */
typedef int (*sw_state_dpp_bcm_trill_mask_set_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_out_ac_set */
typedef int (*sw_state_dpp_bcm_trill_trill_out_ac_set_cb)(
    int unit, SOC_PPC_AC_ID trill_out_ac);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_out_ac_get */
typedef int (*sw_state_dpp_bcm_trill_trill_out_ac_get_cb)(
    int unit, SOC_PPC_AC_ID *trill_out_ac);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_out_ac_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_out_ac_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_local_in_lif_set */
typedef int (*sw_state_dpp_bcm_trill_trill_local_in_lif_set_cb)(
    int unit, SOC_PPC_LIF_ID trill_local_in_lif);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_local_in_lif_get */
typedef int (*sw_state_dpp_bcm_trill_trill_local_in_lif_get_cb)(
    int unit, SOC_PPC_LIF_ID *trill_local_in_lif);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_local_in_lif_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_local_in_lif_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_global_in_lif_set */
typedef int (*sw_state_dpp_bcm_trill_trill_global_in_lif_set_cb)(
    int unit, int trill_global_in_lif);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_global_in_lif_get */
typedef int (*sw_state_dpp_bcm_trill_trill_global_in_lif_get_cb)(
    int unit, int *trill_global_in_lif);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_global_in_lif_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_global_in_lif_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_last_used_id_set */
typedef int (*sw_state_dpp_bcm_trill_last_used_id_set_cb)(
    int unit, int last_used_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_last_used_id_get */
typedef int (*sw_state_dpp_bcm_trill_last_used_id_get_cb)(
    int unit, int *last_used_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_last_used_id_verify */
typedef int (*sw_state_dpp_bcm_trill_last_used_id_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_alloc */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_alloc_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_is_allocated */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_free */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_set */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_set_cb)(
    int unit, int allocated_cnt);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_get */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_get_cb)(
    int unit, int *allocated_cnt);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_port_cnt_set */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_port_cnt_set_cb)(
    int unit, int port_cnt);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_port_cnt_get */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_port_cnt_get_cb)(
    int unit, int *port_cnt);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_port_cnt_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_port_cnt_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_ports_set */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_ports_set_cb)(
    int unit, int ports_idx_0, bcm_gport_t ports);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_ports_get */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_ports_get_cb)(
    int unit, int ports_idx_0, bcm_gport_t *ports);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_ports_alloc */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_ports_alloc_cb)(
    int unit, int nof_instances_to_alloc);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_ports_is_allocated */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_ports_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_ports_free */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_ports_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_trill_ports_ports_verify */
typedef int (*sw_state_dpp_bcm_trill_trill_ports_ports_verify_cb)(
    int unit, int ports_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_set */
typedef int (*sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_set_cb)(
    int unit, int mc_trill_route_info_db_htb_handle);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_get */
typedef int (*sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_get_cb)(
    int unit, int *mc_trill_route_info_db_htb_handle);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_verify */
typedef int (*sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_set */
typedef int (*sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_set_cb)(
    int unit, int mc_trill_root_src_db_htb_handle);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_get */
typedef int (*sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_get_cb)(
    int unit, int *mc_trill_root_src_db_htb_handle);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_verify */
typedef int (*sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

/*********************************** access calbacks struct ****************************************/
/* this set of structs, rooted at 'sw_state_cbs_t' define the access layer for the entire SW state.*/
/* use this tree to alloc/free/set/get fields in the sw state rooted at 'sw_state_t'.              */
/* NOTE: 'sw_state_t' data should not be accessed directly.                                        */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_init_cbs_s {
    sw_state_dpp_bcm_trill_init_set_cb set;
    sw_state_dpp_bcm_trill_init_get_cb get;
    sw_state_dpp_bcm_trill_init_verify_cb verify;
} sw_state_dpp_bcm_trill_init_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_mask_set_cbs_s {
    sw_state_dpp_bcm_trill_mask_set_set_cb set;
    sw_state_dpp_bcm_trill_mask_set_get_cb get;
    sw_state_dpp_bcm_trill_mask_set_verify_cb verify;
} sw_state_dpp_bcm_trill_mask_set_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_out_ac_cbs_s {
    sw_state_dpp_bcm_trill_trill_out_ac_set_cb set;
    sw_state_dpp_bcm_trill_trill_out_ac_get_cb get;
    sw_state_dpp_bcm_trill_trill_out_ac_verify_cb verify;
} sw_state_dpp_bcm_trill_trill_out_ac_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_local_in_lif_cbs_s {
    sw_state_dpp_bcm_trill_trill_local_in_lif_set_cb set;
    sw_state_dpp_bcm_trill_trill_local_in_lif_get_cb get;
    sw_state_dpp_bcm_trill_trill_local_in_lif_verify_cb verify;
} sw_state_dpp_bcm_trill_trill_local_in_lif_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_global_in_lif_cbs_s {
    sw_state_dpp_bcm_trill_trill_global_in_lif_set_cb set;
    sw_state_dpp_bcm_trill_trill_global_in_lif_get_cb get;
    sw_state_dpp_bcm_trill_trill_global_in_lif_verify_cb verify;
} sw_state_dpp_bcm_trill_trill_global_in_lif_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_last_used_id_cbs_s {
    sw_state_dpp_bcm_trill_last_used_id_set_cb set;
    sw_state_dpp_bcm_trill_last_used_id_get_cb get;
    sw_state_dpp_bcm_trill_last_used_id_verify_cb verify;
} sw_state_dpp_bcm_trill_last_used_id_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_cbs_s {
    sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_set_cb set;
    sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_get_cb get;
    sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_verify_cb verify;
} sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_ports_port_cnt_cbs_s {
    sw_state_dpp_bcm_trill_trill_ports_port_cnt_set_cb set;
    sw_state_dpp_bcm_trill_trill_ports_port_cnt_get_cb get;
    sw_state_dpp_bcm_trill_trill_ports_port_cnt_verify_cb verify;
} sw_state_dpp_bcm_trill_trill_ports_port_cnt_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_ports_ports_cbs_s {
    sw_state_dpp_bcm_trill_trill_ports_ports_set_cb set;
    sw_state_dpp_bcm_trill_trill_ports_ports_get_cb get;
    sw_state_dpp_bcm_trill_trill_ports_ports_alloc_cb alloc;
    sw_state_dpp_bcm_trill_trill_ports_ports_is_allocated_cb is_allocated;
    sw_state_dpp_bcm_trill_trill_ports_ports_free_cb free;
    sw_state_dpp_bcm_trill_trill_ports_ports_verify_cb verify;
} sw_state_dpp_bcm_trill_trill_ports_ports_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_trill_ports_cbs_s {
    sw_state_dpp_bcm_trill_trill_ports_alloc_cb alloc;
    sw_state_dpp_bcm_trill_trill_ports_is_allocated_cb is_allocated;
    sw_state_dpp_bcm_trill_trill_ports_free_cb free;
    sw_state_dpp_bcm_trill_trill_ports_verify_cb verify;
    sw_state_dpp_bcm_trill_trill_ports_allocated_cnt_cbs_t allocated_cnt;
    sw_state_dpp_bcm_trill_trill_ports_port_cnt_cbs_t port_cnt;
    sw_state_dpp_bcm_trill_trill_ports_ports_cbs_t ports;
} sw_state_dpp_bcm_trill_trill_ports_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_cbs_s {
    sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_set_cb set;
    sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_get_cb get;
    sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_verify_cb verify;
} sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_cbs_s {
    sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_set_cb set;
    sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_get_cb get;
    sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_verify_cb verify;
} sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_bcm_trill_cbs_s {
#if defined(BCM_PETRA_SUPPORT)
    sw_state_dpp_bcm_trill_alloc_cb alloc;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#if defined(BCM_PETRA_SUPPORT)
    sw_state_dpp_bcm_trill_is_allocated_cb is_allocated;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#if defined(BCM_PETRA_SUPPORT)
    sw_state_dpp_bcm_trill_free_cb free;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#if defined(BCM_PETRA_SUPPORT)
    sw_state_dpp_bcm_trill_verify_cb verify;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
    sw_state_dpp_bcm_trill_init_cbs_t init;
    sw_state_dpp_bcm_trill_mask_set_cbs_t mask_set;
    sw_state_dpp_bcm_trill_trill_out_ac_cbs_t trill_out_ac;
    sw_state_dpp_bcm_trill_trill_local_in_lif_cbs_t trill_local_in_lif;
    sw_state_dpp_bcm_trill_trill_global_in_lif_cbs_t trill_global_in_lif;
    sw_state_dpp_bcm_trill_last_used_id_cbs_t last_used_id;
    sw_state_dpp_bcm_trill_trill_ports_cbs_t trill_ports;
    sw_state_dpp_bcm_trill_mc_trill_route_info_db_htb_handle_cbs_t mc_trill_route_info_db_htb_handle;
    sw_state_dpp_bcm_trill_mc_trill_root_src_db_htb_handle_cbs_t mc_trill_root_src_db_htb_handle;
} sw_state_dpp_bcm_trill_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

int sw_state_dpp_bcm_trill_access_cb_init(int unit);

#endif /* _SHR_SW_STATE_DPP_BCM_TRILL_ACCESS_H_ */
