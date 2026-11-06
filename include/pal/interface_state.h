#ifndef PAL_INTERFACE_STATE_H
#define PAL_INTERFACE_STATE_H

#include "common.h"

typedef struct {
    u8 pad00[0x11];
    u8 flags11[11];
    u8 flags1C[8];
    u8 values24[2];
    u8 values26[2];
} PalInterfaceState;

extern PalInterfaceState D_00171C00;

#endif
