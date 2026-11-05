/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type3 {
    char _p0[0x10];
    s32 f10;
    char f14[0x40];
    s32 f54;
} Type3;

typedef struct Type4 {
    char *f0;
    char **f4;
    s32 f8;
    s32 fC;
    char **f10;
} Type4;

s32 func_01E9B978(void *, s32, s32, void *, s32, s32, s32);
s32 func_L00_00566950(void);
void func_L00_005669C0(void);
void *func_L00_005669E0(s32);
s32 func_L00_00566BA0(void *, s32);
void func_L00_00566D00(void *, void *);
s32 func_L00_00566D60(s32);
extern char D_00488428[];
extern Type4 D_00488530[];
extern char *D_004A9BB8[];
extern char *D_004A9BC0[];

Type4 *func_L00_005682A0(s32 arg0) {
    char buf[16];
    Type3 *ctx;
    s32 r;
    Type4 *h = D_00488530;

    ctx = func_L00_005669E0(0);
    if (ctx != 0) {
        ctx->f10 = 0;
        func_L00_005669C0();
        r = func_01E9B978(ctx->f14, ctx->f54, 0x41, buf, arg0, 0, 0);
        if (func_L00_00566950() < 0) {
            ctx->f10 = -1;
            func_L00_00566BA0(ctx, -1);
        } else if (r < 0) {
            if (r == -500 || r == -515) {
                ctx->f10 = 1;
                func_L00_00566BA0(ctx, 0);
            } else if (r == -516) {
                ctx->f10 = 2;
                func_L00_00566BA0(ctx, 0);
            } else if (r == -517) {
                ctx->f10 = 3;
                func_L00_00566BA0(ctx, 0);
            } else if (r == -518) {
                ctx->f10 = 4;
                func_L00_00566BA0(ctx, 0);
            } else {
                ctx->f10 = -1;
                func_L00_00566BA0(ctx, func_L00_00566D60(r));
            }
        } else {
            h->f0 = 0;
            h->f4 = D_004A9BB8;
            h->f8 = 2;
            h->fC = 4;
            func_L00_00566D00(D_00488428, buf);
            ctx->f10 = 0;
            D_004A9BC0[0] = D_00488428;
            h->f10 = D_004A9BC0;
            func_L00_00566BA0(ctx, 0);
            return h;
        }
    }
    return 0;
}
