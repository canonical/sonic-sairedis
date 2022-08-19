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

#ifndef _SHR_SW_STATE_DPP_SOC_ARAD_PP_EG_ENCAP_ACCESS_H_
#define _SHR_SW_STATE_DPP_SOC_ARAD_PP_EG_ENCAP_ACCESS_H_

/********************************* access calbacks definitions *************************************/
/* this set of callbacks, are the callbacks used in the access calbacks struct 'sw_state_cbs_t' to */
/* access the data in 'sw_state_t'.                                                                */
/* the calbacks are inserted into the access struct by 'sw_state_access_cb_init'.                  */
/***************************************************************************************************/

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_set */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_set_cb)(
    int unit, CONST ARAD_PP_SW_DB_EG_ENCAP *eg_encap);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_get */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_get_cb)(
    int unit, ARAD_PP_SW_DB_EG_ENCAP *eg_encap);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_alloc */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_alloc_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_is_allocated */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_is_allocated_cb)(
    int unit, uint8 *is_allocated);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_free */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_free_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_verify */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_verify_cb)(
    int unit);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_prog_data_set */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_prog_data_set_cb)(
    int unit, SOC_SAND_MULTI_SET_PTR prog_data);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_prog_data_get */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_prog_data_get_cb)(
    int unit, SOC_SAND_MULTI_SET_PTR *prog_data);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* implemented by: sw_state_dpp_soc_arad_pp_eg_encap_prog_data_verify */
typedef int (*sw_state_dpp_soc_arad_pp_eg_encap_prog_data_verify_cb)(
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
typedef struct sw_state_dpp_soc_arad_pp_eg_encap_prog_data_cbs_s {
    sw_state_dpp_soc_arad_pp_eg_encap_prog_data_set_cb set;
    sw_state_dpp_soc_arad_pp_eg_encap_prog_data_get_cb get;
    sw_state_dpp_soc_arad_pp_eg_encap_prog_data_verify_cb verify;
} sw_state_dpp_soc_arad_pp_eg_encap_prog_data_cbs_t;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
typedef struct sw_state_dpp_soc_arad_pp_eg_encap_cbs_s {
    sw_state_dpp_soc_arad_pp_eg_encap_set_cb set;
    sw_state_dpp_soc_arad_pp_eg_encap_get_cb get;
    sw_state_dpp_soc_arad_pp_eg_encap_alloc_cb alloc;
    sw_state_dpp_soc_arad_pp_eg_encap_is_allocated_cb is_allocated;
    sw_state_dpp_soc_arad_pp_eg_encap_free_cb free;
    sw_state_dpp_soc_arad_pp_eg_encap_verify_cb verify;
    sw_state_dpp_soc_arad_pp_eg_encap_prog_data_cbs_t prog_data;
} sw_state_dpp_soc_arad_pp_eg_encap_cbs_t;

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

int sw_state_dpp_soc_arad_pp_eg_encap_access_cb_init(int unit);

#endif /* _SHR_SW_STATE_DPP_SOC_ARAD_PP_EG_ENCAP_ACCESS_H_ */
