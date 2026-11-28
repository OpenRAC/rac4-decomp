#ifndef PAL_MENU_FLOW_H
#define PAL_MENU_FLOW_H

#include "common.h"

typedef struct PalMenuFlowEntry {
    s32 f0;
    s32 f4;
    char name[20];
    void (*callback)(struct PalMenuFlowEntry *);
    s32 f20;
} PalMenuFlowEntry;

typedef struct {
    u32 state;
    u8 pad4[0x78];
    s32 timer;
    u8 pad80[4];
    s32 entryCount;
    PalMenuFlowEntry entries[6];
    u8 started;
} PalMenuFlow;

extern PalMenuFlow D_003097A8;

#endif
