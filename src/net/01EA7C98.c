/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0x2C];
    s32 (*f2C)();
};
struct Type2 {
    char _p0[0x8];
    s32 f8;
    s32 fC;
};

s32 func_01EA8928(Type2 *);
s32 func_01EA89E0(s32, s32, s32);
extern Type1 *D_00167F34;

s32 func_01EA7C98(Type2 *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 v;
    *arg1 = 0;
    if (func_01EA8928(arg0) == 0) {
        return 2;
    }
    if (arg0->fC != 3) {
        return 0xC355;
    }
    v = D_00167F34->f2C(arg0->f8, arg1, arg2, arg3);
    if (v != 0) {
        return v;
    }
    if (*arg1 != 0) {
        func_01EA89E0(0, 0x1C, 0);
    }
    return 0;
}
