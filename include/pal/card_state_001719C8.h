#ifndef RAC4_PAL_CARD_STATE_001719C8_H
#define RAC4_PAL_CARD_STATE_001719C8_H

#include "common.h"

typedef struct {
    u8 pad00[0x1B0];
    s32 selectedRecord;
    u8 pad1B4[0x10];
    s32 f1C4;
    s32 f1C8;
    s32 f1CC;
    s32 f1D0;
    s32 f1D4;
} PalCardState;

extern PalCardState D_001719C8[];

#endif
