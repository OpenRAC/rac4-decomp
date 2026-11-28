#ifndef RAC4_PAL_L00_ROSTER_001E0DF8_H
#define RAC4_PAL_L00_ROSTER_001E0DF8_H

#include "common.h"

typedef struct {
    s32 ids[20];
    s32 count;
    u8 pad54[0x10];
} PalRosterSlot;

typedef struct Roster {
    u8 pad0[0x18];
    s32 x18;
    s32 x1C;
    u8 pad20[8];
    PalRosterSlot slots[10];
    u8 names[10][16];
    s32 f4B0[10];
    u8 pad4D8[0x28];
    s32 team[10];
    u8 pad528[0x190];
    s16 kills[10];
    u8 pad6CC[0xF4];
    s32 score[10];
    u8 pad7E8[0x28];
    s32 ids[10];
} Roster;

extern Roster D_001E0DF8;

#endif
