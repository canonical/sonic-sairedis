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

#ifndef _SHR_SW_STATE_DPP_SOC_ARAD_TM_TM_INFO_ACCESS_H_
#define _SHR_SW_STATE_DPP_SOC_ARAD_TM_TM_INFO_ACCESS_H_

/********************************* access calbacks definitions *************************************/
/* this set of callbacks, are the callbacks used in the access calbacks struct 'sw_state_cbs_t' to */
/* access the data in 'sw_state_t'.                                                                */
/* the calbacks are inserted into the access struct by 'sw_state_access_cb_init'.                  */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_alloc */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_alloc_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_is_allocated */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_free */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_set_cb)(
    int unit, uint8 is_power_saving_called);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_get_cb)(
    int unit, uint8 *is_power_saving_called);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_set_cb)(
    int unit, CONST ARAD_SW_DB_QUEUE_TO_RATE_CLASS_MAPPING *queue_to_rate_class_mapping);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_get_cb)(
    int unit, ARAD_SW_DB_QUEUE_TO_RATE_CLASS_MAPPING *queue_to_rate_class_mapping);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_set_cb)(
    int unit, uint8 is_simple_mode);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_get_cb)(
    int unit, uint8 *is_simple_mode);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_set_cb)(
    int unit, int ref_count_idx_0, int ref_count_idx_1, uint32 ref_count);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_get_cb)(
    int unit, int ref_count_idx_0, int ref_count_idx_1, uint32 *ref_count);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_verify_cb)(
    int unit, int ref_count_idx_0, int ref_count_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_set_cb)(
    int unit, int ocb_only_ref_count_idx_0, int ocb_only_ref_count_idx_1, uint32 ocb_only_ref_count);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_get_cb)(
    int unit, int ocb_only_ref_count_idx_0, int ocb_only_ref_count_idx_1, uint32 *ocb_only_ref_count);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_verify_cb)(
    int unit, int ocb_only_ref_count_idx_0, int ocb_only_ref_count_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_set_cb)(
    int unit, int sysport2basequeue_idx_0, CONST ARAD_SW_DB_SYSPORT_TO_BASE_QUEUE *sysport2basequeue);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_get_cb)(
    int unit, int sysport2basequeue_idx_0, ARAD_SW_DB_SYSPORT_TO_BASE_QUEUE *sysport2basequeue);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_alloc */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_alloc_cb)(
    int unit, int nof_instances_to_alloc);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_is_allocated */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_free */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_verify_cb)(
    int unit, int sysport2basequeue_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_set_cb)(
    int unit, int sysport2basequeue_idx_0, uint8 valid_flags);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_get_cb)(
    int unit, int sysport2basequeue_idx_0, uint8 *valid_flags);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_verify_cb)(
    int unit, int sysport2basequeue_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_set_cb)(
    int unit, int sysport2basequeue_idx_0, uint32 base_queue);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_get_cb)(
    int unit, int sysport2basequeue_idx_0, uint32 *base_queue);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_verify_cb)(
    int unit, int sysport2basequeue_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_set_cb)(
    int unit, int queuequartet2sysport_idx_0, ARAD_SYSPORT queuequartet2sysport);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_get_cb)(
    int unit, int queuequartet2sysport_idx_0, ARAD_SYSPORT *queuequartet2sysport);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_alloc */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_alloc_cb)(
    int unit, int nof_instances_to_alloc);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_is_allocated */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_free */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_verify_cb)(
    int unit, int queuequartet2sysport_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_groups_bw_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_groups_bw_set_cb)(
    int unit, int groups_bw_idx_0, int groups_bw_idx_1, int groups_bw);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_groups_bw_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_groups_bw_get_cb)(
    int unit, int groups_bw_idx_0, int groups_bw_idx_1, int *groups_bw);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_groups_bw_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_groups_bw_verify_cb)(
    int unit, int groups_bw_idx_0, int groups_bw_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_set_cb)(
    int unit, int hr_group_bw_idx_0, int hr_group_bw_idx_1, int hr_group_bw);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_get_cb)(
    int unit, int hr_group_bw_idx_0, int hr_group_bw_idx_1, int *hr_group_bw);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_verify_cb)(
    int unit, int hr_group_bw_idx_0, int hr_group_bw_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_set_cb)(
    int unit, int rcy_single_context_port_idx_0, int rcy_single_context_port_idx_1, int rcy_single_context_port);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_get_cb)(
    int unit, int rcy_single_context_port_idx_0, int rcy_single_context_port_idx_1, int *rcy_single_context_port);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_verify_cb)(
    int unit, int rcy_single_context_port_idx_0, int rcy_single_context_port_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_set_cb)(
    int unit, int rcy_reassembly_ctxt_idx_0, int rcy_reassembly_ctxt_idx_1, uint32 rcy_reassembly_ctxt);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_get_cb)(
    int unit, int rcy_reassembly_ctxt_idx_0, int rcy_reassembly_ctxt_idx_1, uint32 *rcy_reassembly_ctxt);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_verify_cb)(
    int unit, int rcy_reassembly_ctxt_idx_0, int rcy_reassembly_ctxt_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_set_cb)(
    int unit, int rcy_channels_to_egr_nif_mapping_idx_0, int rcy_channels_to_egr_nif_mapping_idx_1, int rcy_channels_to_egr_nif_mapping);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_get_cb)(
    int unit, int rcy_channels_to_egr_nif_mapping_idx_0, int rcy_channels_to_egr_nif_mapping_idx_1, int *rcy_channels_to_egr_nif_mapping);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_verify_cb)(
    int unit, int rcy_channels_to_egr_nif_mapping_idx_0, int rcy_channels_to_egr_nif_mapping_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_pg_numq_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_pg_numq_set_cb)(
    int unit, int pg_numq_idx_0, int pg_numq_idx_1, uint8 pg_numq);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_pg_numq_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_pg_numq_get_cb)(
    int unit, int pg_numq_idx_0, int pg_numq_idx_1, uint8 *pg_numq);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_pg_numq_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_pg_numq_verify_cb)(
    int unit, int pg_numq_idx_0, int pg_numq_idx_1);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_set_cb)(
    int unit, CONST ARAD_SW_DB_CREDIT_WATCHDOG *credit_watchdog);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_get_cb)(
    int unit, ARAD_SW_DB_CREDIT_WATCHDOG *credit_watchdog);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_set_cb)(
    int unit, int8 credit_watchdog_mode);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_get_cb)(
    int unit, int8 *credit_watchdog_mode);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_set_cb)(
    int unit, uint32 exact_credit_watchdog_scan_time_nano);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_get_cb)(
    int unit, uint32 *exact_credit_watchdog_scan_time_nano);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_set */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_set_cb)(
    int unit, SOC_TMC_SCH_FLOW_IPF_CONFIG_MODE ipf_config_mode);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_get */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_get_cb)(
    int unit, SOC_TMC_SCH_FLOW_IPF_CONFIG_MODE *ipf_config_mode);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_verify */
typedef int (*sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_verify_cb)(
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
typedef struct sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_verify_cb verify;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_is_simple_mode_cbs_t is_simple_mode;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ref_count_cbs_t ref_count;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_ocb_only_ref_count_cbs_t ocb_only_ref_count;
} sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_alloc_cb alloc;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_is_allocated_cb is_allocated;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_free_cb free;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_verify_cb verify;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_valid_flags_cbs_t valid_flags;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_base_queue_cbs_t base_queue;
} sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_alloc_cb alloc;
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_is_allocated_cb is_allocated;
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_free_cb free;
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_groups_bw_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_groups_bw_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_groups_bw_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_groups_bw_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_groups_bw_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_pg_numq_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_pg_numq_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_pg_numq_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_pg_numq_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_pg_numq_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_verify_cb verify;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_credit_watchdog_mode_cbs_t credit_watchdog_mode;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_exact_credit_watchdog_scan_time_nano_cbs_t exact_credit_watchdog_scan_time_nano;
} sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_set_cb set;
    sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_get_cb get;
    sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_verify_cb verify;
} sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_tm_tm_info_cbs_s {
    sw_state_dpp_soc_arad_tm_tm_info_alloc_cb alloc;
    sw_state_dpp_soc_arad_tm_tm_info_is_allocated_cb is_allocated;
    sw_state_dpp_soc_arad_tm_tm_info_free_cb free;
    sw_state_dpp_soc_arad_tm_tm_info_verify_cb verify;
    sw_state_dpp_soc_arad_tm_tm_info_is_power_saving_called_cbs_t is_power_saving_called;
    sw_state_dpp_soc_arad_tm_tm_info_queue_to_rate_class_mapping_cbs_t queue_to_rate_class_mapping;
    sw_state_dpp_soc_arad_tm_tm_info_sysport2basequeue_cbs_t sysport2basequeue;
    sw_state_dpp_soc_arad_tm_tm_info_queuequartet2sysport_cbs_t queuequartet2sysport;
    sw_state_dpp_soc_arad_tm_tm_info_groups_bw_cbs_t groups_bw;
    sw_state_dpp_soc_arad_tm_tm_info_hr_group_bw_cbs_t hr_group_bw;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_single_context_port_cbs_t rcy_single_context_port;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_reassembly_ctxt_cbs_t rcy_reassembly_ctxt;
    sw_state_dpp_soc_arad_tm_tm_info_rcy_channels_to_egr_nif_mapping_cbs_t rcy_channels_to_egr_nif_mapping;
    sw_state_dpp_soc_arad_tm_tm_info_pg_numq_cbs_t pg_numq;
    sw_state_dpp_soc_arad_tm_tm_info_credit_watchdog_cbs_t credit_watchdog;
    sw_state_dpp_soc_arad_tm_tm_info_ipf_config_mode_cbs_t ipf_config_mode;
} sw_state_dpp_soc_arad_tm_tm_info_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

int sw_state_dpp_soc_arad_tm_tm_info_access_cb_init(int unit);

#endif /* _SHR_SW_STATE_DPP_SOC_ARAD_TM_TM_INFO_ACCESS_H_ */
