#include "common.h"

extern s32 D_0030F6F0[];
#define D_3098F0 (D_0030F6F0[0])

void func_L00_0063E7D0(s32 arg0) {
    *((s32 *)((u32)&D_3098F0 + (arg0 * 0x1F8))) = 0;
}
