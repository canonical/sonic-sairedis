/*
 * $Id: $
 * 
 * $Copyright: (c) 2020 Broadcom.
 * Broadcom Proprietary and Confidential. All rights reserved.$
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#ifndef __BCM_BCMI2C_H__
#define __BCM_BCMI2C_H__

#if defined(INCLUDE_I2C)

#include <bcm/types.h>

#ifndef BCM_HIDE_DISPATCHABLE

/* Open I2C device. */
extern int bcm_i2c_open(
    int unit, 
    char *devname, 
    uint32 flags, 
    int speed);

/* Write to I2C device. */
extern int bcm_i2c_write(
    int unit, 
    int fd, 
    uint32 addr, 
    uint8 *data, 
    uint32 nbytes);

/* Read from I2C device. */
extern int bcm_i2c_read(
    int unit, 
    int fd, 
    uint32 addr, 
    uint8 *data, 
    uint32 *nbytes);

/* Perform IOCTL access on I2C driver. */
extern int bcm_i2c_ioctl(
    int unit, 
    int fd, 
    int opcode, 
    void *data, 
    int len);

#endif /* defined(INCLUDE_I2C) */

#endif /* BCM_HIDE_DISPATCHABLE */

#endif /* __BCM_BCMI2C_H__ */
