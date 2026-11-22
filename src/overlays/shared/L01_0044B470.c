#include "common.h"

extern void func_00451938(f32, void *, void *, s32, s32);
extern s32 D_00222B28;

void func_L01_0044B470(void *arg0) {
    u8 *base = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 *src = (s32 *)(base + 0x34);
    u8 *dst = base + 0x60;
    s32 i = 3;
    do {
        s32 v = *src;
        src++;
        func_00451938(1.0f, &D_00222B28, dst, 2, v);
        i--;
        dst += 0x80;
    } while (i >= 0);
}
