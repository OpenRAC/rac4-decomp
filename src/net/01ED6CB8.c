/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char b[0x50]; s32 f50; } Req;
typedef struct { s32 f0; void *f4; char f8[0x18]; } Ctx;
typedef struct { s32 w[4]; } Res;
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BCA74;
extern s32 D_001BC87C;
extern s32 func_01ED5DD0(s32, s32, s32, void *);
extern s32 func_01E9E4A8(Ctx *);
extern void func_01ED5570(char *);
extern void func_01ED5658(void);
extern void func_01ED5590(s32);
extern void func_01ED56B8(s32, Req *);
extern s32 func_01E9E4F8(Ctx *, Res *);
s32 func_01ED6CB8(Req *r, s32 b, s32 c) {
    Ctx ctx;
    Res res;
    s32 mode;
    r->b[0x14] = 0;
    r->b[0x25] = 0;
    r->b[0x4F] = 0;
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    if (D_00169CD4 == 0) {
        return -0x10;
    }
    mode = r->f50;
    D_001BCA74 = b;
    D_001BC87C = c;
    if (mode == 2) {
        if (func_01E9E4A8(&ctx) != 0) {
            return -2;
        }
        func_01ED5570(ctx.f8);
        ctx.f4 = func_01ED5658;
        func_01ED5590(3);
        func_01ED56B8(0x2D, r);
        if (func_01E9E4F8(&ctx, &res) == 0) {
            return 0;
        }
        func_01ED5590(0);
        return -2;
    }
    return func_01ED5DD0(1, 0xF3, 0xC4, r) != 0 ? -5 : 0;
}
