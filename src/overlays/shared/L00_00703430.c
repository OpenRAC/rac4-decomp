#include "common.h"

extern void func_01E9E270(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, void *t1);
extern u8 D_172160[];
extern s32 D_00212104[];

// Pass the message at arg0 to func_01E9E270 when the +0x258 word of D_172160 is zero; the size is 0x12 when bit 2 of the first byte is set, else 0x18.
void func_L00_00703430(u8 *arg0) {
    u8 *base = D_172160;
    s32 size = 0x18;
    s32 flag = arg0[0] & 4;

    if (flag) {
        size = 0x12;
    }
    if (*(s32 *)(base + 0x258) == 0) {
        func_01E9E270(base[0x7F8], *(s32 *)(base + 8), -1, D_00212104[0], size, arg0);
    }
}
