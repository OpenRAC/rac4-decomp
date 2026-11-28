#ifndef PAL_MENU_SELECTION_0030A260_H
#define PAL_MENU_SELECTION_0030A260_H

#include "common.h"

typedef struct {
    s32 phase;
    s32 selected;
    s32 first;
    s32 second;
} PalResidentOptionState;

extern u8 D_0030A260[];

static inline PalResidentOptionState *pal_resident_option_state(s32 context) {
    return (PalResidentOptionState *)((u32)D_0030A260 + (u32)context * sizeof(PalResidentOptionState));
}

#endif
