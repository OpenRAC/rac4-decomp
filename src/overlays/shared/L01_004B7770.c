#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x610];
    u8 f610;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};

s32 func_L00_005E60A0(s32);

s32 func_L01_004B7770(Type1 *arg0) {
    s32 r = 1;
    if (arg0->fAC->f610 != 0) {
        if (func_L00_005E60A0(2) == 0) goto zero;
        r = 1;
    }
    return r;
zero:
    return 0;
}
