#include "common.h"

// True when pvar+0x68 equals 1.

typedef struct Type2 {
    char _p0[0x68];
    s32 f94;
} Type2;

typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
} Type1;

s32 func_L15_003F8B68(Type1 *arg0) {
    return arg0->fAC->f94 == 1;
}
