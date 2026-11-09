#include "common.h"

typedef int s128 __attribute__((mode(TI)));

s32 func_0051BB40(void *, s32, f32, f32, f32);
extern f32 D_0021DDEC;
extern f32 D_0021DDF4;

/* Copies state into a block at 0x1790, calls func_0051BB40 with scaled factors, then updates the counter at 0x60C. */
void func_0051AEF8(u8 *arg0) {
    f32 t;
    f32 v;

    if (*(u8 *)(arg0 + 0x266D) == 0 || *(s16 *)(*(u8 **)(*(u8 **)(arg0 + 0x2EFC) + 0x50) + 0x86) != 0x21) {
        *(f32 *)(arg0 + 0x17A0) = *(f32 *)(arg0 + 0x2CE8);
        *(f32 *)(arg0 + 0x17A4) = *(f32 *)(arg0 + 0x5FC);
        *(s128 *)(arg0 + 0x1790) = *(s128 *)(arg0 + 0x2CF0);
        t = *(f32 *)(arg0 + 0x25C4);
        func_0051BB40(arg0, 0, D_0021DDEC * 0.042f * t, D_0021DDEC * 0.25f * t, D_0021DDF4 * 19.198622f * t);
        v = *(f32 *)(arg0 + 0x17A8);
        *(f32 *)(arg0 + 0x62C) = v;
        *(f32 *)(arg0 + 0x5FC) = *(f32 *)(arg0 + 0x17A4);
        if (v == 0.0f) {
            *(s32 *)(arg0 + 0x60C) = *(s32 *)(arg0 + 0x60C) + 1;
            return;
        }
        *(s32 *)(arg0 + 0x60C) = 0;
    }
}
