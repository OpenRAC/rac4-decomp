/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    u8 pad0[4];
    u8 *f4;
} Type2;

typedef struct {
    u8 pad0[0x150];
    union { u64 v; s32 i; } f150;
    s32 f158;
    u8 pad15C[0x168 - 0x15C];
    s32 f168;
} Type3;

typedef struct {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[0x3C - 0x34];
    union { s32 i; Type2 *p; } f3C;
    s32 f40;
    u8 pad44[0x54 - 0x44];
    union { s32 i; Type3 *p; } f54;
} Type1;

extern void func_L00_004F84C8(int, int, int, int, int);
extern s32 func_L00_00505478(Type1 *, s32, u8 *, s32);
extern void func_L00_00505D50(Type1 *, s32, s32);
extern s32 func_L00_00516FC0(Type2 *, s32);
extern s32 func_L00_00528540(Type1 *, s32);

/* Reads a length-prefixed message (1 type byte, 3 length bytes) then its body. */
s64 func_L00_00527340(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3, u64 arg4, s32 *arg5) {
    u8 *buf;
    s32 n;
    s32 err;
    u64 len;
    s64 total;
    s64 remaining;

    if (arg0->f54.p->f168 != 0) {
        arg0->f54.p->f168 = 0;
        if (arg3 >= 0 && arg0->f54.p->f158 != arg3) {
            err = 10;
            func_L00_004F84C8(0x14, 0x8E, 0xF4, 0, 0);
            goto fail;
        }
        *arg5 = 1;
        return arg0->f54.p->f150.v;
    }
    buf = arg0->f3C.p->f4;
    if (arg0->f30 == arg1) {
head:
        n = func_L00_00505478(arg0, 0x16, buf + arg0->f40, 4 - arg0->f40);
        if (n < 4 - arg0->f40) {
            if (n <= 0) {
                goto readfail;
            }
            arg0->f40 += n;
            goto head;
        }
        if (arg3 >= 0 && buf[0] != arg3) {
            err = 10;
            func_L00_004F84C8(0x14, 0x8E, 0xF4, 0, 0);
            goto fail;
        }
        arg0->f54.p->f158 = buf[0];
        buf++;
        len = ((u64)buf[0] << 16) | ((u64)buf[1] << 8) | buf[2];
        if (arg4 < len) {
            err = 0x2F;
            func_L00_004F84C8(0x14, 0x8E, 0x98, 0, 0);
            goto fail;
        }
        if (len != 0 && func_L00_00516FC0(arg0->f3C.p, len) == 0) {
            func_L00_004F84C8(0x14, 0x8E, 0x807, 0, 0);
            *arg5 = 0;
            return -1;
        }
        arg0->f54.p->f150.v = len;
        arg0->f30 = arg2;
        arg0->f40 = 0;
    }
    total = arg0->f54.p->f150.v;
    buf = arg0->f3C.p->f4;
    remaining = total;
    if (total > 0) {
body:
        n = func_L00_00505478(arg0, 0x16, buf + arg0->f40, (s32)remaining);
        if (n != (s32)remaining) {
            remaining -= n;
            if (n <= 0) {
                goto readfail;
            }
            arg0->f40 += n;
            goto body;
readfail:
            *arg5 = 0;
            return func_L00_00528540(arg0, n);
        }
    }
    *arg5 = 1;
    return total;
fail:
    func_L00_00505D50(arg0, 2, err);
    *arg5 = 0;
    return -1;
}
