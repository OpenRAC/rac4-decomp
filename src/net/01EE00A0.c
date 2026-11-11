/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
    s32 f8;
    s32 fC;
    char _p10[0x18];
    s32 f28;
    s32 f2C;
};

s32 func_0011EAA0(void *, s32, void *);
s32 func_01EAE190(void *, void *, s32);
s32 func_01EE10F0(void *);
extern s32 D_00199F28[];
extern s32 D_0019A108[];
extern s32 D_0019A198[];
extern s32 D_0019A1A8[];

s32 func_01EE00A0(Type1 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_v1;

    if (arg2 != 1) {
        func_0011EAA0(D_00199F28, 0x385, D_0019A198);
    }
    if (*arg1 != 1) {
        func_0011EAA0(D_00199F28, 0x386, D_0019A1A8);
    }
    if ((arg0->f8 == 0) && (arg0->fC == 0)) {
        func_01EE10F0(arg0);
    }
    temp_v1 = arg0->f4;
    arg0->fC = temp_v1;
    if ((u32) (temp_v1 - 3) < 2U) {
        func_01EAE190((void *)((u8 *)arg0 + 0x312), (void *)((u8 *)arg0 + 0x140), 0x10);
    } else {
        func_0011EAA0(D_00199F28, 0x3AB, D_0019A108);
    }
    arg0->f28 = 0;
    arg0->f2C = 0;
    return arg2;
}
