/* cflags: -fno-opt-stack -mcheck-zero-division */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);

// Writes the digits between arg1 and arg2 backwards into a stack buffer, inserting commas every three digits, then copies the text out.
u32 func_00123B40(u32 arg0, u32 arg1, u32 arg2, s32 *arg3) {
    s32 n;
    s32 s0;
    s32 t0;
    s32 div3;
    u32 p;
    u8 *a3;
    s8 v1;
    u8 c;
    s32 sp[4];
    u8 *buf;

    n = arg2 - arg1;
    s0 = n + 0xA;
    buf = __builtin_alloca(s0);
    t0 = 0;
    a3 = buf + s0 - 1;
    if (arg0 == 0) {
        return 0;
    }
    if (arg1 == 0) {
        return 0;
    }
    if (arg2 == 0) {
        return 0;
    }
    p = arg1;
    sp[0] = 0;
    sp[1] = arg2;
    if (arg2 >= p) {
        for (;;) {
            v1 = *(s8 *)p;
            switch (v1) {
            case 0x2E:
                sp[1] = p;
                if (sp[0] == 0) {
                    sp[0] = 1;
                }
                break;
            case 0x45:
            case 0x65:
                sp[0] = 2;
                break;
            }
            p += 1;
            if (arg2 < p || sp[0] == 2) {
                break;
            }
        }
    }
    if (sp[0] == 2) {
        return arg1;
    }
    p = arg2;
    if (arg1 < p) {
        div3 = 3;
        do {
            *a3 = *(u8 *)p;
            a3 -= 1;
            if ((u32)sp[1] >= p) {
                if (t0 % div3 == 0 && t0 != 0) {
                    *a3 = 0x2C;
                    s0 += 1;
                    a3 -= 1;
                }
                t0 += 1;
            }
            p -= 1;
        } while (arg1 < p);
    }
    c = *(u8 *)p;
    s0 -= 0xA;
    *a3 = c;
    func_0011A370((u8 *)arg0, a3, s0);
    *arg3 = s0;
    return arg0;
}
