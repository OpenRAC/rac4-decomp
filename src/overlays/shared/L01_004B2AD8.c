#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x410];
    s32 f410;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};

s32 func_L01_004B2D40(void *);
s32 func_L01_004B3CC8(void *);
s32 func_L01_004B3D18(void *);


void func_L01_004B2AD8(Type1 *arg0) {
    if ((arg0->fAC->f410 != 0) && (func_L01_004B3D18(arg0) != 0)) {
        func_L01_004B2D40(arg0);
        func_L01_004B3CC8(arg0);
    }
}
