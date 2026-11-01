#ifndef PAL_OBJECT_PARAMETER_H
#define PAL_OBJECT_PARAMETER_H

#include "common.h"

typedef struct {
    u32 flags;
    u8 pad04[8];
    s32 dirty;
    u8 pad10[0xF4];
    f32 value;
    s16 duration;
} PalObjectParameter;

#endif
