/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern s8 D_00220AB2;
extern void *D_002234A4;

void func_L00_0070D078(void) {
    *(s32 *)((u8 *)D_002234A4 + 0x24) = 0;
    *(s32 *)((u8 *)D_002234A4 + 0x20) = 0;
    D_00220AB2 = 0;
}