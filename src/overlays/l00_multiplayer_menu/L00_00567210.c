/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    struct Type1 *f0;
    struct Type1 *f4;
    s32 f8;
    char _pC[0x8];
    s32 f14;
    char _p18[0x4C];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} Type1;

extern void *func_0011A518(void *, s32, s32);
void *func_L00_005669E0(s32);
s32 func_L00_00566BA0(void *, s32);
s32 func_L00_00566E60(void);
Type1 *func_L00_005668D8(s32);
extern Type1 *D_004A9BA0[];
extern Type1 *D_004A9BA4[];

s32 func_L00_00567210(s32 arg0, s32 arg1) {
    void *ctx;
    s32 id;
    Type1 *node;

    ctx = func_L00_005669E0(0);
    if (ctx == 0) {
        return -1;
    }
    if (arg0 != 2) {
        return func_L00_00566BA0(ctx, 0x60);
    }
    id = func_L00_00566E60();
    switch (arg1) {
    case 2:
        arg1 = 0;
        break;
    case 1:
    case 3:
        break;
    default:
        return func_L00_00566BA0(ctx, 0x6B);
    }
    node = func_L00_005668D8(0x78);
    if (node == 0) {
        return func_L00_00566BA0(ctx, 0xC);
    }
    func_0011A518(node, 0, 0x78);
    node->f8 = id;
    node->f14 = arg1;
    node->f64 = -1;
    node->f68 = -1;
    node->f6C = -1;
    node->f70 = -1;
    node->f74 = -1;
    node->f0 = D_004A9BA0[0];
    if (D_004A9BA0[0] != 0) {
        D_004A9BA0[0]->f4 = node;
    } else {
        D_004A9BA4[0] = node;
    }
    D_004A9BA0[0] = node;
    node->f4 = 0;
    func_L00_00566BA0(ctx, 0);
    return id;
}
