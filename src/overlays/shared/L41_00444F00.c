#include "common.h"

extern s32 D_003980C0[];

// Sets two words of the sub-object at +0xAC to a global OR 0x1F000000.
void func_L41_00444F00(u8 *arg0) {
    u8 *sub = *(u8 **)(arg0 + 0xAC);
    s32 v = D_003980C0[0] | 0x1F000000;
    *(s32 *)(sub + 0x6C) = v;
    *(s32 *)(sub + 0x68) = v;
}
