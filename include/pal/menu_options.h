#ifndef PAL_MENU_OPTIONS_H
#define PAL_MENU_OPTIONS_H

#include "common.h"

typedef struct {
    s32 value;
    s32 kind;
    s32 f08;
    s32 f0C;
} MenuOption;

typedef struct {
    u8 pad00[4];
    s32 f04;
    u8 pad08[0x18];
    s32 f20[5];
    u8 pad34[0x114];
    s32 f148[20];
} MenuOptionValues;

extern MenuOption D_L00_004B7310[];
s32 func_L00_007102B0(s32 index, s32 value);

#endif
