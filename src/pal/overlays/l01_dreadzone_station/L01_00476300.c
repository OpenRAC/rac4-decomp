/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 D_00221A30 = 0;

void func_L01_00476300(s32 arg0) {
    u8 temp_3;
    if (D_00221A30 == 0) goto block_8;
    temp_3 = *(u8 *)((u8 *)D_00221A30 + 0x20);
    if (temp_3 == 0xFE) goto block_8;
    if (temp_3 == 0xFD) goto block_8;
    if (*(s16 *)((u8 *)D_00221A30 + 0xBC) != 0x2748) goto block_8;
    if (arg0 != 0) {
        *(s32 *)((u8 *)D_00221A30 + 0x98) = *(s32 *)((u8 *)*(void **)((u8 *)D_00221A30 + 0x24) + 0x10);
        return;
    }
    *(s32 *)((u8 *)D_00221A30 + 0x98) = 0;
block_8:
    return;
}
