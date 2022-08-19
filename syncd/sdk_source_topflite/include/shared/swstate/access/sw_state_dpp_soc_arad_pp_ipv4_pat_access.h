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

#ifndef _SHR_SW_STATE_DPP_SOC_ARAD_PP_IPV4_PAT_ACCESS_H_
#define _SHR_SW_STATE_DPP_SOC_ARAD_PP_IPV4_PAT_ACCESS_H_

/********************************* access calbacks definitions *************************************/
/* this set of callbacks, are the callbacks used in the access calbacks struct 'sw_state_cbs_t' to */
/* access the data in 'sw_state_t'.                                                                */
/* the calbacks are inserted into the access struct by 'sw_state_access_cb_init'.                  */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_alloc */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_alloc_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_is_allocated */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_free */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_verify */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_set */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_set_cb)(
    int unit, int occ_bm_hndl_idx_0, SOC_SAND_OCC_BM_PTR occ_bm_hndl);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_get */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_get_cb)(
    int unit, int occ_bm_hndl_idx_0, SOC_SAND_OCC_BM_PTR *occ_bm_hndl);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_alloc */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_alloc_cb)(
    int unit, int nof_instances_to_alloc);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_is_allocated */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_free */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_verify */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_verify_cb)(
    int unit, int occ_bm_hndl_idx_0);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_nof_set */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_nof_set_cb)(
    int unit, int nof);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_nof_get */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_nof_get_cb)(
    int unit, int *nof);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_nof_verify */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_nof_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_counter_set */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_counter_set_cb)(
    int unit, int counter);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_counter_get */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_counter_get_cb)(
    int unit, int *counter);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_ipv4_pat_counter_verify */
typedef int (*sw_state_dpp_soc_arad_pp_ipv4_pat_counter_verify_cb)(
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
typedef struct sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_cbs_s {
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_set_cb set;
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_get_cb get;
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_alloc_cb alloc;
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_is_allocated_cb is_allocated;
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_free_cb free;
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_verify_cb verify;
} sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_pp_ipv4_pat_nof_cbs_s {
    sw_state_dpp_soc_arad_pp_ipv4_pat_nof_set_cb set;
    sw_state_dpp_soc_arad_pp_ipv4_pat_nof_get_cb get;
    sw_state_dpp_soc_arad_pp_ipv4_pat_nof_verify_cb verify;
} sw_state_dpp_soc_arad_pp_ipv4_pat_nof_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_pp_ipv4_pat_counter_cbs_s {
    sw_state_dpp_soc_arad_pp_ipv4_pat_counter_set_cb set;
    sw_state_dpp_soc_arad_pp_ipv4_pat_counter_get_cb get;
    sw_state_dpp_soc_arad_pp_ipv4_pat_counter_verify_cb verify;
} sw_state_dpp_soc_arad_pp_ipv4_pat_counter_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_pp_ipv4_pat_cbs_s {
    sw_state_dpp_soc_arad_pp_ipv4_pat_alloc_cb alloc;
    sw_state_dpp_soc_arad_pp_ipv4_pat_is_allocated_cb is_allocated;
    sw_state_dpp_soc_arad_pp_ipv4_pat_free_cb free;
    sw_state_dpp_soc_arad_pp_ipv4_pat_verify_cb verify;
    sw_state_dpp_soc_arad_pp_ipv4_pat_occ_bm_hndl_cbs_t occ_bm_hndl;
    sw_state_dpp_soc_arad_pp_ipv4_pat_nof_cbs_t nof;
    sw_state_dpp_soc_arad_pp_ipv4_pat_counter_cbs_t counter;
} sw_state_dpp_soc_arad_pp_ipv4_pat_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

int sw_state_dpp_soc_arad_pp_ipv4_pat_access_cb_init(int unit);

#endif /* _SHR_SW_STATE_DPP_SOC_ARAD_PP_IPV4_PAT_ACCESS_H_ */
