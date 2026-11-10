/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 func_00550790(void *, void *, void *, void *, void *, s32, s32);
extern u8 D_00222B20[];

void func_L01_0045BF60(void *arg0) {
    u8 *linked = *(u8 **)((u8 *)arg0 + 0xAC);
    func_00550790(D_00222B20, arg0, (u8 *)arg0 + 0x10, (u8 *)arg0 + 0xF0, linked + 0x5F0, 1, 0);
    *(s16 *)(linked + 0x60E) = 0x78;
}
