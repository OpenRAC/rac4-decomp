#ifndef PAL_MENU_STATE_00309940_H
#define PAL_MENU_STATE_00309940_H

#include "common.h"

typedef struct {
    s32 unknown00;
    s32 phase;
    f32 current;
    f32 target;
    u8 pad10[4];
    s32 color;
    u8 pad18[8];
    f32 progress;
    u8 unknown24;
    u8 flag25;
    u8 pad26[2];
    s32 f28;
    u8 update;
    u8 pad2D[7];
    s32 f34;
} PalMenuState00309940;

extern PalMenuState00309940 D_00309940[];

#endif
