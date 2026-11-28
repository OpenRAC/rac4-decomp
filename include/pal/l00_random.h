#ifndef RAC4_PAL_L00_RANDOM_H
#define RAC4_PAL_L00_RANDOM_H

#include "common.h"

extern s32 func_L00_0050CF78(void);

static inline u32 random_byte(void) {
    return (u32)((f32)func_L00_0050CF78() / 2147483520.0f * 256.0f);
}

#endif
