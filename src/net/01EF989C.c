/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u32 func_01EED8A4(s32, s32, s32);
extern s32 func_01EEE12C(void);
extern void func_01EEF6A8(void *a, void *b);
extern s32 func_01EF4188(void *a, void *b, s32 c, s32 d, s32 e);
extern void func_01EF9DD8(void *arg0, s32 arg1);
extern void func_01EFA118(void *, s8, s32);
extern void func_01EFB098(void *a);
extern void func_01EFB128(void *a);
extern void func_01F0C090(char *arg0, s32 arg1);
extern char D_0019D240[];

/* Runs the object's per-frame hooks, then reads its state record and sends the matching packets. */
s32 func_01EF989C(void *arg0, s32 arg1) {
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u8 *vt;
    s32 v;

    s0 = arg0;
    if (*(s32 *)(s0 + 0x18C) == 0) {
        vt = *(u8 **)(s0 + 0xB0);
        v = (*(s32 (**)(void *))(vt + 0x20))(s0);
        if (v != 0 && *(s32 *)(s0 + 0x190) == 0) {
            *(s32 *)(s0 + 0x190) = 1;
            func_01EF9DD8(s0, *(s32 *)(s0 + 0x138));
        } else {
            vt = *(u8 **)(s0 + 0xB0);
            if ((*(s32 (**)(void *))(vt + 0x20))(s0) == 0 && *(s32 *)(s0 + 0x190) != 0) {
                *(s32 *)(s0 + 0x190) = 0;
                func_01EF9DD8(s0, *(s32 *)(s0 + 0x12C));
            }
        }
    }
    vt = *(u8 **)(s0 + 0xB0);
    if ((*(s32 (**)(void *))(vt + 0x20))(s0) == 0) {
        return 1;
    }
    s2 = (u8 *)func_01EEE12C();
    s1 = *(u8 **)(*(u8 **)(s0 + 0x80) + 4);
    if (*(s32 *)s0 == 0) {
        func_01F0C090(D_0019D240, 0x13C);
    }
    if (s1 == 0) {
        func_01F0C090(D_0019D240, 0x13D);
    }
    if (arg1 == 0) {
        func_01F0C090(D_0019D240, 0x13E);
    }
    v = func_01EED8A4((s32)s1, 0x11, 4);
    if (v != 0 || (v = func_01EED8A4((s32)s1, 0x11, 5)) != 0) {
        func_01EFA118(s0, v, 0);
    }
    if (*(s32 *)(s2 + 0x24) == 0) {
        if (func_01EED8A4((s32)s1, 0x11, 0) != 0 || func_01EED8A4((s32)s1, 0x11, 1) != 0 || func_01EED8A4((s32)s1, 0x11, 2) != 0 || func_01EED8A4((s32)s1, 0x11, 3) != 0) {
            s2 = *(u8 **)(*(u8 **)(s0 + 0x80));
            if (s2 == 0) {
                func_01F0C090(D_0019D240, 0x155);
            }
            return func_01EF4188(s0, s1, s2, *(s32 *)s0, arg1) == 0;
        }
        if (func_01EED8A4((s32)s1, 0x11, 6) != 0) {
            func_01EFB098(s0);
        }
        if (func_01EED8A4((s32)s1, 0x11, 7) != 0) {
            func_01EFB128(s0);
        }
        vt = *(u8 **)(s0 + 0xB0);
        if ((*(s32 (**)(void *))(vt + 0x2C))(s0) != 0) {
            if (func_01EED8A4((s32)s1, 0x11, 0x12) != 0) {
                func_01EEF6A8(s2, s0);
            }
            vt = *(u8 **)(s0 + 0xB0);
            (*(void (**)(void *, void *))(vt + 0x68))(s0, s1);
        }
    } else {
        vt = *(u8 **)(s1 + 0xD8);
        (*(void (**)(void *, void *))(vt + 0x30))(s1, s0);
    }
    return 1;
}
