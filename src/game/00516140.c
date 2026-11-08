#include "common.h"

extern void func_00162760(s32);
extern void func_00547C90(s32, s32, s32);
extern s32 func_00548DA0(s32, s32);
extern s32 func_0054A4A0(s32, s32, s32, s32);
extern s32 func_0054A580(s32, s32, s32);
extern s32 D_0021DFE8;

void func_00516140(u8 *arg0) {
    s32 i;
    s32 n;
    u8 *sub;

    if (*(s32 *)(arg0 + 0x2F14) == 1) {
        i = 1;
        do {
            s32 next;
            n = 10;
            next = i + 1;
            while (--n != -1) {
                if (func_0054A4A0(*(s32 *)(arg0 + 0x26E4), i, 2, 0) == 0) {
                    break;
                }
            }
            func_0054A580(*(s32 *)(arg0 + 0x26E4), i, 0);
            i = next;
        } while (i < 20);
        for (n = 2; n < 20; n++) {
            if (func_00548DA0(*(s32 *)(arg0 + 0x26E4), n) & 0xFF) {
                func_00547C90(*(s32 *)(arg0 + 0x26E4), n, 0);
            }
        }
    }
    *(u8 *)(D_0021DFE8 + *(s32 *)(arg0 + 0x2F10) + 0xFA) = 0;
    *(s32 *)(arg0 + 0x2F14) = 0;
    (*(u8 **)(arg0 + 0x2EF0))[0xBE] |= 0x10;
    (*(u8 **)(arg0 + 0x2EF0))[0xBE] &= 0xF7;
    *(u16 *)(arg0 + 0x1FCA) = *(s32 *)(arg0 + 0x2F14);
    sub = *(u8 **)(arg0 + 0x2F28);
    if (sub != 0) {
        u8 *inner = *(u8 **)(sub + 4);
        if (inner != 0) {
            *(s32 *)(inner + 0x40) = *(s32 *)(arg0 + 0x2F14);
        }
    }
    *(f32 *)(arg0 + 0x2F24) = 50.0f;
    if (arg0[0x266D] != 0) {
        func_00162760(1);
    }
    (*(u8 **)(arg0 + 0x2EF0))[0x23] = 0x80;
    *(u16 *)(*(u8 **)(arg0 + 0x2EF0) + 0x34) &= 0xDFFF;
    *(u16 *)(*(u8 **)(arg0 + 0x2EF0) + 0x36) &= 0xFFF7;
}
