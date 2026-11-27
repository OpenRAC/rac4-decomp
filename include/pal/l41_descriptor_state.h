#ifndef PAL_L41_DESCRIPTOR_STATE_H
#define PAL_L41_DESCRIPTOR_STATE_H

#include "common.h"

typedef struct L41DescriptorState {
    u8 unknown00[0x68];
    s32 value68;
    u8 unknown6C[0x14];
    s32 status80;
} L41DescriptorState;

typedef struct L41DescriptorObject {
    u8 unknown00[0xAC];
    L41DescriptorState *state;
} L41DescriptorObject;

extern L41DescriptorObject *D_L41_00221A10;

#endif