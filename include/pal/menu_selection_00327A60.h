#ifndef RAC4_PAL_MENU_SELECTION_00327A60_H
#define RAC4_PAL_MENU_SELECTION_00327A60_H

#include "common.h"

typedef struct {
    u8 unknown[8];
    s16 item;
    s16 slot;
} PalMenuSelection;

extern PalMenuSelection D_00327A60[];

#endif
