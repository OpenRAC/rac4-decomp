#include "common.h"

extern s32 func_L00_006CE468(s32);
extern void func_004E8DD0(f32, void *, void *, s32, s32, s32);

void func_L01_0044AC50(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0xAC);
    if (p != 0 && *(s32 *)(p + 0x24) != 0 && func_L00_006CE468(*(s32 *)(p + 0x30)) != 0) {
        func_004E8DD0(1.0f, p, p + 0x10, 0, 1, 0);
    }
}
