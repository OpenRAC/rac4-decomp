#include "common.h"

void func_L01_00558B80(void *context, u8 *state, s32 propagate)
{
    s32 index;

    *(s32 *)(state + 0xAC) = 1;
    if (propagate != 0) {
        for (index = 0; index < *(s32 *)(state + 0xA4); index++) {
            u8 *child = ((u8 **)(state + 0x10))[index];
            child[0xB] = 1;
        }
    }
}
