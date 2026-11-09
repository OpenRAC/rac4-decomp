/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type540C10;

extern void func_0011A518(void *, s32, s32);
extern s32 func_L00_00519490(void *ctx, s32 arg1);
extern void func_L00_00519578(void *ctx, void *data, u32 len);
extern void func_L00_005195A8(void *ctx, u8 *out, u32 *outLen);
extern void *func_L00_0051A740(void);
extern void func_L00_0051A7B8(void *ctx);

s32 func_L00_00540C10(Type540C10 *info, s32 kind, u8 *extra, u8 *data, s32 dataLen,
                      s32 rounds, u8 *out0, u8 *out1)
{
    void *ctx;
    u8 buf[32];
    s32 n0;
    s32 n1;
    s32 pass = 0;
    u32 len = 0;
    u32 i;

    n0 = info->f8;
    n1 = info->fC;
    if (data == 0) {
        return n0;
    }
    ctx = func_L00_0051A740();
    if (ctx == 0) {
        return 0;
    }
    for (;;) {
        if (!func_L00_00519490(ctx, kind)) {
            func_L00_0051A7B8(ctx);
            return 0;
        }
        if (++pass != 1) {
            func_L00_00519578(ctx, buf, len);
        }
        func_L00_00519578(ctx, data, dataLen);
        if (extra != 0) {
            func_L00_00519578(ctx, extra, 8);
        }
        func_L00_005195A8(ctx, buf, &len);
        for (i = 1; i < (u32)rounds; i++) {
            func_L00_00519490(ctx, kind);
            func_L00_00519578(ctx, buf, len);
            func_L00_005195A8(ctx, buf, &len);
        }
        i = 0;
        if (n0) {
            for (;;) {
                if (n0 == 0) break;
                if (i == len) break;
                if (out0 != 0) {
                    *out0++ = buf[i];
                }
                n0--;
                i++;
            }
        }
        if (n1 && i != len) {
            for (;;) {
                if (n1 == 0) break;
                if (i == len) break;
                if (out1 != 0) {
                    *out1++ = buf[i];
                }
                n1--;
                i++;
            }
        }
        if (n0 == 0 && n1 == 0) break;
    }
    func_L00_0051A7B8(ctx);
    func_0011A518(buf, 0, 20);
    return info->f8;
}
