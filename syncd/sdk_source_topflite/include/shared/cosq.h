/*
 * $Id: cosq.h,v 1.4 Broadcom SDK $
 * $Copyright: (c) 2020 Broadcom.
 * Broadcom Proprietary and Confidential. All rights reserved.$
 *
 * This file defines COSQ constants 
 *
 * Its contents are not used directly by applications; it is used only
 * by header files of parent APIs which need to share  COSQ constants.
 */

#ifndef _SHR_COSQ_H
#define _SHR_COSQ_H

#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_WHOLE_SHIFT    0
#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_WHOLE_MASK     0xFFFF
#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_FRACT_SHIFT    (16)
#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_FRACT_MASK     0xFFFF

#define _SHR_COSQ_GPORT_PRIORITY_PROFILE_SHIFT                  16
#define _SHR_COSQ_GPORT_PRIORITY_PROFILE_MASK			        0x07

/* 
 *  COSQ macros for bcm_cosq_control_t types
 */
#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_SET(whole_utilization, fractional_utilization) \
              (((whole_utilization & _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_WHOLE_MASK) <<           \
                                        _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_WHOLE_SHIFT) |        \
               ((fractional_utilization & _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_FRACT_MASK) <<      \
                                        _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_FRACT_SHIFT))

#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_WHOLE_GET(utilization)                         \
                ((utilization >> _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_WHOLE_SHIFT) & _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_WHOLE_MASK)


#define _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTILIZATION_FRACTIONAL_GET(utilization)                    \
                ((utilization >> _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_FRACT_SHIFT) & _SHR_COSQ_CONTROL_FABRIC_CONNECT_MIN_UTIL_FRACT_MASK)


/*
 * priority profile template
 */
#define _SHR_COSQ_GPORT_PRIORITY_PROFILE_SET(_flags, _profile)             \
    _flags = _flags | ((_profile & _SHR_COSQ_GPORT_PRIORITY_PROFILE_MASK) << _SHR_COSQ_GPORT_PRIORITY_PROFILE_SHIFT)
#define _SHR_COSQ_GPORT_PRIORITY_PROFILE_GET(_flags)                       \
    ((_flags >> _SHR_COSQ_GPORT_PRIORITY_PROFILE_SHIFT) & _SHR_COSQ_GPORT_PRIORITY_PROFILE_MASK)

typedef enum _shr_cosq_threshold_type_e {
    _SHR_COSQ_THRESHOLD_BYTES,
    _SHR_COSQ_THRESHOLD_PACKET_DESCRIPTORS,
    _SHR_COSQ_THRESHOLD_PACKETS,
    _SHR_COSQ_THRESHOLD_DATA_BUFFERS,
    _SHR_COSQ_THRESHOLD_AVAILABLE_PACKET_DESCRIPTORS,
    _SHR_COSQ_THRESHOLD_AVAILABLE_DATA_BUFFERS,
    _SHR_COSQ_THRESHOLD_BUFFER_DESCRIPTOR_BUFFERS,
    _SHR_COSQ_THRESHOLD_BUFFER_DESCRIPTORS,
    _SHR_COSQ_THRESHOLD_DBUFFS,
    _SHR_COSQ_THRESHOLD_FULL_DBUFFS,
    _SHR_COSQ_THRESHOLD_MINI_DBUFFS,
    _SHR_COSQ_THRESHOLD_DYNAMIC_WEIGHT,
    _SHR_COSQ_THRESHOLD_PACKET_DESCRIPTORS_MIN,
    _SHR_COSQ_THRESHOLD_PACKET_DESCRIPTORS_MAX,
    _SHR_COSQ_THRESHOLD_PACKET_DESCRIPTORS_ALPHA,
    _SHR_COSQ_THRESHOLD_DATA_BUFFERS_MIN,
    _SHR_COSQ_THRESHOLD_DATA_BUFFERS_MAX,
    _SHR_COSQ_THERESHOLD_DATA_BUFFERS_ALPHA,
    _SHR_COSQ_THRESHOLD_OCB_DBUFFS,
    _SHR_COSQ_THRESHOLD_PACKET_DESCRIPTOR_BUFFERS,
    _SHR_COSQ_THRESHOLD_BUNDLE_DESCRIPTOR_BUFFERS,
    _SHR_COSQ_THERESHOLD_DATA_BUFFERS_ALPHA1,
    _SHR_COSQ_THRESHOLD_OCB_PACKET_DESCRIPTOR_BUFFERS,
    _SHR_COSQ_THRESHOLD_NUM
} _shr_cosq_threshold_type_t;


/*
 * COSQ_TH_INDEX support 
 */
#define _SHR_COSQ_TH_INDEX_DP_INDICATION           (0x01000000)
#define _SHR_COSQ_TH_INDEX_TC_INDICATION           (0x02000000)
#define _SHR_COSQ_TH_INDEX_POOL_DP_INDICATION      (0x03000000)
#define _SHR_COSQ_TH_INDEX_CLASS_FWDACT_INDICATION (0x04000000)
#define _SHR_COSQ_TH_INDEX_PRIO_INDICATION         (0x05000000)
#define _SHR_COSQ_TH_INDEX_POOL_PRIO_INDICATION    (0x06000000)

#define _SHR_COSQ_TH_INDEX_INDICATION_MASK         (0xff000000)

/** Each field is assigned 4 bits which is more than required for each of the fields */
#define _SHR_COSQ_TH_INDEX_FIELD_NOF_BITS              (4)
#define _SHR_COSQ_TH_INDEX_FIELD_MASK                  ( (1 << _SHR_COSQ_TH_INDEX_FIELD_NOF_BITS) - 1) /** unshifted mask */

#define _SHR_COSQ_TH_INDEX_DP_SET(dp) \
        (_SHR_COSQ_TH_INDEX_DP_INDICATION | (dp & _SHR_COSQ_TH_INDEX_FIELD_MASK))

#define _SHR_COSQ_TH_INDEX_TC_SET(tc) \
        (_SHR_COSQ_TH_INDEX_TC_INDICATION | (tc & _SHR_COSQ_TH_INDEX_FIELD_MASK))

#define _SHR_COSQ_TH_INDEX_POOL_DP_SET(pool_id, dp) \
        (_SHR_COSQ_TH_INDEX_POOL_DP_INDICATION | \
        ((pool_id & _SHR_COSQ_TH_INDEX_FIELD_MASK) << _SHR_COSQ_TH_INDEX_FIELD_NOF_BITS) | \
         (dp & _SHR_COSQ_TH_INDEX_FIELD_MASK))

#define _SHR_COSQ_TH_INDEX_CAST_PRIO_FWDACT_SET(cast, priority, forward_action) \
        (_SHR_COSQ_TH_INDEX_CLASS_FWDACT_INDICATION | \
         ((cast & _SHR_COSQ_TH_INDEX_FIELD_MASK) << (2 * _SHR_COSQ_TH_INDEX_FIELD_NOF_BITS)) | \
         ((priority & _SHR_COSQ_TH_INDEX_FIELD_MASK) << _SHR_COSQ_TH_INDEX_FIELD_NOF_BITS) | \
         (forward_action & _SHR_COSQ_TH_INDEX_FIELD_MASK))

#define _SHR_COSQ_TH_INDEX_PRIO_SET(prio) \
        (_SHR_COSQ_TH_INDEX_PRIO_INDICATION | (prio & _SHR_COSQ_TH_INDEX_FIELD_MASK))

#define _SHR_COSQ_TH_INDEX_POOL_PRIO_SET(pool_id, prio) \
        (_SHR_COSQ_TH_INDEX_POOL_PRIO_INDICATION | \
        ((pool_id & _SHR_COSQ_TH_INDEX_FIELD_MASK) << _SHR_COSQ_TH_INDEX_FIELD_NOF_BITS) | \
         (prio & _SHR_COSQ_TH_INDEX_FIELD_MASK))

/*
* COSQ_GENERIC_KEY support
*/
#define _SHR_COSQ_GENERIC_KEY_COLOR_INDICATION              (1)
#define _SHR_COSQ_GENERIC_KEY_LATENCY_BIN_COLOR_INDICATION  (2)
#define _SHR_COSQ_GENERIC_KEY_COLOR_MASK                    (3)
#define _SHR_COSQ_GENERIC_KEY_COLOR_SHIFT                   (8)
#define _SHR_COSQ_GENERIC_KEY_COLOR_SIZE                    (2)
#define _SHR_COSQ_GENERIC_KEY_LATENCY_BIN_COLOR_SHIFT       (_SHR_COSQ_GENERIC_KEY_COLOR_SHIFT + _SHR_COSQ_GENERIC_KEY_COLOR_SIZE)


#define _SHR_COSQ_GENERIC_KEY_COLOR_SET(key, color) \
        ((key) = (_SHR_COSQ_GENERIC_KEY_COLOR_INDICATION | (color << _SHR_COSQ_GENERIC_KEY_COLOR_SHIFT)))
#define _SHR_COSQ_GENERIC_KEY_COLOR_GET(key) \
        (key >> _SHR_COSQ_GENERIC_KEY_COLOR_SHIFT)
#define _SHR_COSQ_GENERIC_KEY_LAT_BIN_COLOR_SET(key, bin, color) \
        ((key) = (_SHR_COSQ_GENERIC_KEY_LATENCY_BIN_COLOR_INDICATION | (color << _SHR_COSQ_GENERIC_KEY_COLOR_SHIFT) | \
        (bin << _SHR_COSQ_GENERIC_KEY_LATENCY_BIN_COLOR_SHIFT)))
#define _SHR_COSQ_GENERIC_KEY_LAT_BIN_COLOR_BIN_GET(key) \
        (key >> _SHR_COSQ_GENERIC_KEY_LATENCY_BIN_COLOR_SHIFT)
#define _SHR_COSQ_GENERIC_KEY_LAT_BIN_COLOR_COLOR_GET(key) \
        ((key >> _SHR_COSQ_GENERIC_KEY_COLOR_SHIFT) & _SHR_COSQ_GENERIC_KEY_COLOR_MASK)

#endif /* !_SHR_COSQ_H */
