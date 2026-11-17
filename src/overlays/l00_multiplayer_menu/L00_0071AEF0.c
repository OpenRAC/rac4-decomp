#include "common.h"

extern void *func_L00_00710750(void *arg0);
extern s32 D_004B9E90[];

// Reset the record at arg0: store its table pointer, clear the table at +0x22C and set the sentinels.
void *func_L00_0071AEF0(void *arg0) {
    s32 *var_v1;
    s32 var_a0;

    func_L00_00710750(arg0);
    *(s32 *)((u8 *)arg0 + 0x58) = (s32)D_004B9E90;
    var_a0 = 0x5F;
    var_v1 = (s32 *)((u8 *)arg0 + 0x22C);
    *((u8 *)arg0 + 0x234) = 0;
    *(u32 *)((u8 *)arg0 + 0x23C) = 0xFFFFFFFF;
    *(s32 *)((u8 *)arg0 + 0xAC) = 0;
    *(u32 *)((u8 *)arg0 + 0x240) = 0xFFFFFFFF;
    do {
        *var_v1 = 0;
        var_a0 -= 1;
        var_v1 -= 1;
    } while (var_a0 >= 0);
    *(s32 *)((u8 *)arg0 + 0x9C) = *(s32 *)((u8 *)arg0 + 0x254) = *(s32 *)((u8 *)arg0 + 0x250) =
        *(s32 *)((u8 *)arg0 + 0x230) = -1;
    *(s32 *)((u8 *)arg0 + 0xA0) = -1;
    *(s32 *)((u8 *)arg0 + 0x24C) = (s32)((u8 *)arg0 + 0x260);
    return arg0;
}
