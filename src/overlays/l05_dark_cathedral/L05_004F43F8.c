#include "common.h"

// True when the pvar's +0x11 equals 1.

typedef struct Type2 {
    char _p0[0x11];
    u8 f16;
} Type2;

typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
} Type1;

s32 func_L05_004F43F8(Type1 *arg0) {
    return arg0->fAC->f16 == 1;
}
