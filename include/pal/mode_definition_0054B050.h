#ifndef RAC4_PAL_MODE_DEFINITION_0054B050_H
#define RAC4_PAL_MODE_DEFINITION_0054B050_H

#include "common.h"

typedef struct {
    u8 unknown0[0xD];
    u8 allowed[10];
    u8 unknown17[5];
    u16 texture;
    u8 unknown1E[0x1A];
} PalModeDefinition;

extern const PalModeDefinition *func_0054B050(s32);

#endif
