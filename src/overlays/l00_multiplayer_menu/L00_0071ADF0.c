#include "common.h"

// Store arg1/arg2 and copy up to 0x33 chars of the name arg3 (empty when null).

typedef struct Type1 {
    char _p0[0x4];
    s32 f4;
    s32 f8;
    char fC[0x33];
    char f3F;
} Type1;

extern void func_0011AFC8(char *arg0, char *arg1, s32 arg2);

void func_L00_0071ADF0(Type1 *arg0, u32 arg1, s32 arg2, char *arg3) {
    arg0->f4 = arg1;
    arg0->f8 = arg2;
    if (arg3 != 0) {
        func_0011AFC8(arg0->fC, arg3, 0x33);
        arg0->f3F = 0;
    } else {
        arg0->fC[0] = 0;
    }
}
