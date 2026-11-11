/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004EF078 (src/levels/39_multiplayer_menu/L39_004ECE38.c, GPL-3.0), the same code in both games. */

extern s32 func_L00_0051A6E0(s32);
extern void *func_L00_0051AE10(void);
extern void func_L00_0051AEE0(void *);
extern s32 func_L00_0051AF58(void *, void *);
extern s32 func_L00_0051B060(void *, u8 *, s32, s32);
extern void func_L00_0051B208(void *, void *, s32);
extern s32 func_L00_0051B210(void *, u8 *, s32 *);
extern void func_0011A370(void *, void *, s32);
extern void func_0011A518(void *, s32, s32);
s32 func_L00_0052AE78(s32 md, u8 *sec, s32 sec_len, s32 seed, s32 seed_len, u8 *out, s32 olen) {
    s32 chunk;
    s32 j;
    void *ctx;
    void *ctx_tmp;
    u8 A1[0x40];
    s32 A1_len;
    s32 ret = 0;
    chunk = func_L00_0051A6E0(md);
    ctx = func_L00_0051AE10();
    ctx_tmp = func_L00_0051AE10();
    if (ctx == 0 || ctx_tmp == 0) {
        goto err;
    }
    if (!func_L00_0051B060(ctx, sec, sec_len, md)) {
        goto err;
    }
    func_L00_0051B208(ctx, (void *)seed, seed_len);
    if (!func_L00_0051B210(ctx, A1, &A1_len)) {
        goto err;
    }
    for (;;) {
        if (!func_L00_0051B060(ctx, 0, 0, 0)) {
            goto err;
        }
        func_L00_0051B208(ctx, A1, A1_len);
        if (!func_L00_0051AF58(ctx_tmp, ctx)) {
            goto err;
        }
        func_L00_0051B208(ctx, (void *)seed, seed_len);
        if (olen > chunk) {
            if (!func_L00_0051B210(ctx, out, &j)) {
                goto err;
            }
            out += j;
            olen -= j;
            if (!func_L00_0051B210(ctx_tmp, A1, &A1_len)) {
                goto err;
            }
        } else {
            if (!func_L00_0051B210(ctx, A1, &A1_len)) {
                goto err;
            }
            func_0011A370(out, A1, olen);
            break;
        }
    }
    ret = 1;
err:
    if (ctx != 0) {
        func_L00_0051AEE0(ctx);
    }
    if (ctx_tmp != 0) {
        func_L00_0051AEE0(ctx_tmp);
    }
    func_0011A518(A1, 0, 0x40);
    return ret;
}
extern s32 func_L00_0052AE78(s32, u8 *, s32, s32, s32, u8 *, s32);
