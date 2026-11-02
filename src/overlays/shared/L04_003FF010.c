#include "common.h"

// True when the pvar's +0x88 equals 1.

typedef struct Type2 {
    char _p0[0x88];
    u8 f16;
} Type2;

typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
} Type1;

s32 func_L04_003FF010(Type1 *arg0) {
    return arg0->fAC->f16 == 1;
}
