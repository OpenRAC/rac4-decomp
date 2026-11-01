#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x2E4];
    s32 f2E4;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};
/* 32-bit field truncated to u8 on return; check that low eight bits are all that matter. */

u8 func_L01_004CF5D0(Type1 *arg0) {
    return arg0->fAC->f2E4;
}
