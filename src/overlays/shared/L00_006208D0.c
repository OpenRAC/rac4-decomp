#include "common.h"

extern s32 D_002F9208[];

// Record the new value in field 0xBC, marking the record dirty if it changed.
void func_L00_006208D0(s32 arg0) {
    u8 *base = (u8 *)D_002F9208;

    if (*(s32 *)(base + 0xBC) != arg0) {
        *(s32 *)(base + 0xBC) = arg0;
        *(u8 *)D_002F9208 = 1;
    }
}
