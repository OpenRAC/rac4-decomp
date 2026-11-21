/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[8]; u32 f8; u32 fC; char _p10[0x10]; u32 f20; u32 f24; u32 f28; u32 f2C; } Ctx;

extern void func_0011EAA0(char *file, s32 line, char *expr);
extern void func_01EAE980(void *);
extern void *func_01EAEA48(void *, const void *, s32);
extern void func_01EAEBE0(u8 *ctx, u8 *out, u32 len);
extern void func_01EB1C20(s32 *arg0);
extern void *func_01EB1C60(void *, const void *, s32);
extern void func_01EB1DC0(u8 *out, void *ctx);
extern u8 D_00199EB0[];
extern u8 D_00199EE0[];
extern s32 D_00199F28[];
extern s32 D_0019A108[];

/* Builds an 11-byte header from a 64-bit counter at ctx, then hashes it into out for one of three message kinds. */
s32 func_01EE0980(Ctx *ctx, s32 arg1, u8 *arg2, u8 arg3, u8 *arg4, u32 arg5) {
    u8 msg[0xB];
    u8 *end;
    u8 hc0[0x60];
    u8 hc1[0x60];
    u8 *s1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 n;
    s32 ret;

    if (arg1 != 0) {
        t3 = ctx->f20;
        s1 = (u8 *)ctx + 0x110;
        t4 = ctx->f8;
        t2 = ctx->f24;
        n = t3 + 1;
        ctx->f20 = n;
        if (n == 0) {
            ctx->f24 = t2 + 1;
        }
    } else {
        t3 = ctx->f28;
        s1 = (u8 *)ctx + 0x120;
        t4 = ctx->fC;
        t2 = ctx->f2C;
        n = t3 + 1;
        ctx->f28 = n;
        if (n == 0) {
            ctx->f2C = t2 + 1;
        }
    }
    msg[0] = t2 >> 24;
    msg[1] = t2 >> 16;
    msg[2] = t2 >> 8;
    msg[3] = t2;
    msg[4] = t3 >> 24;
    msg[5] = t3 >> 16;
    msg[6] = t3 >> 8;
    msg[7] = t3;
    msg[8] = arg3;
    msg[9] = arg5 >> 8;
    msg[10] = arg5;
    end = &msg[11];
    switch (t4) {
    case 3:
    case 4:
        ret = 0x10;
        func_01EB1C20((s32 *)hc0);
        func_01EB1C60(hc0, s1, 0x10);
        func_01EB1C60(hc0, D_00199EB0, 0x30);
        func_01EB1C60(hc0, msg, end - msg);
        func_01EB1C60(hc0, arg4, arg5);
        func_01EB1DC0(arg2, hc0);
        func_01EB1C20((s32 *)hc0);
        func_01EB1C60(hc0, s1, 0x10);
        func_01EB1C60(hc0, D_00199EE0, 0x30);
        func_01EB1C60(hc0, arg2, 0x10);
        func_01EB1DC0(arg2, hc0);
        break;
    case 5:
        ret = 0x14;
        func_01EAE980(hc1);
        func_01EAEA48(hc1, s1, 0x10);
        func_01EAEA48(hc1, D_00199EB0, 0x28);
        func_01EAEA48(hc1, msg, end - msg);
        func_01EAEA48(hc1, arg4, arg5);
        func_01EAEBE0(hc1, arg2, 0x14);
        func_01EAE980(hc1);
        func_01EAEA48(hc1, s1, 0x10);
        func_01EAEA48(hc1, D_00199EE0, 0x28);
        func_01EAEA48(hc1, arg2, 0x14);
        func_01EAEBE0(hc1, arg2, 0x14);
        break;
    default:
        ret = 0;
        func_0011EAA0((char *)D_00199F28, 0x51A, (char *)D_0019A108);
        break;
    }
    return ret;
}
