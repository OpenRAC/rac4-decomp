#include "common.h"

extern s32 func_00414F48(void *, s32, s32, s32);
extern void func_0046BDD0(s32);
extern u8 D_229CE0[];

/* Fills or releases the 0xC4 slot of entry arg0 in D_229CE0, chosen by the halfword at 0x86 of arg1. */
void func_0043A908(s32 arg0, void *arg1) {
    s32 off = arg0 * 0x470;
    u8 *s0 = D_229CE0 + off;
    s32 t;

    if (*(s16 *)((u8 *)arg1 + 0x86) == 0) {
        if (*(s32 *)(s0 + 0xC4) == 0) {
            *(s32 *)(s0 + 0xC4) = func_00414F48(D_229CE0 + off - 0x60, arg0, off, arg0);
        }
    } else {
        t = *(s32 *)(s0 + 0xC4);
        if (t != 0) {
            func_0046BDD0(t);
            *(s32 *)(s0 + 0xC4) = 0;
        }
    }
}
