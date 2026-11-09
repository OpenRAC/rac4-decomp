/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    char _p0[0x14];
    char f14[0x40];
    s32 f54;
} Type2;
typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    char _p10[0x4];
    s32 f14;
    s32 f18;
    char f1C[0x10];
    s32 f2C;
} Type1;

extern void *func_0011A518(void *, s32, s32);
s32 func_01E9BAE0(void *, s32, s32, s32);
s32 func_1E9BA68(void *, s32, void *);
s32 func_L00_00566BA0(void *, s32);
s32 func_L00_00566D60(s32);
s32 func_L00_00567368(void *, void *);

/* Starts a multiplayer-menu request on arg1 if idle, reporting failures through func_L00_00566D60. */
s32 func_L00_00567650(Type2 *arg0, Type1 *arg1) {
    s32 r;

    if (arg1->fC != 0) {
        return 0;
    }
    if (arg1->f14 != 0 && arg1->f14 != 3) {
        return 0x80;
    }
    func_0011A518(arg1->f1C, 0, 0x10);
    arg1->f2C = 0;
    if (arg1->f18 == 0) {
        arg1->f18 = -1;
    }
    r = func_1E9BA68(arg0->f14, arg0->f54, &arg1->f14);
    if (r <= 0) {
        return func_L00_00566D60(r);
    }
    arg1->fC = r;
    r = func_L00_00567368(arg0, arg1);
    if (r < 0) {
        return func_L00_00566BA0(arg0, func_L00_00566D60(r));
    }
    r = func_01E9BAE0(arg0->f14, arg0->f54, arg1->fC, -1);
    if (r < 0) {
        return func_L00_00566D60(r);
    }
    return 0;
}
