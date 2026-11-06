#ifndef PAL_OBJECT_DATA_H
#define PAL_OBJECT_DATA_H

#include "common.h"

/* Partial object layout used by the PAL data accessors. */
typedef struct {
    u8 pad00[0x34];
    u16 flags;
    u8 pad36[0x76];
    u32 *data;
} PalObject;

#endif
