#ifndef PAL_MASK_STATE_H
#define PAL_MASK_STATE_H

#include "common.h"

typedef struct {
    u8 pad00[0x3C];
    u32 mask3C;
} PalMaskState;

extern u8 *D_0021E070;
extern void *D_0021E078;

#endif
