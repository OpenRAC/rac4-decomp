#ifndef RAC4_PAL_RECORD_001F1480_H
#define RAC4_PAL_RECORD_001F1480_H

#include "common.h"

typedef struct Type001F1480 {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u32 f8;
} Type001F1480;

typedef char Type001F1480_size_check[sizeof(Type001F1480) == 12 ? 1 : -1];
typedef char Type001F1480_alignment_check[__alignof__(Type001F1480) == 4 ? 1 : -1];

extern Type001F1480 D_001F1480[];
extern s32 func_0045E288(s16, s16, u32, s32);
extern s32 func_0045E2D8(s16, s16, u32, s32);

#endif
