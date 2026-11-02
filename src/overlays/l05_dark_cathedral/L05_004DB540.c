#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x430];
    s32 f410;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};

s32 func_L01_004E35D0(void *);
s32 func_L05_004DB948(void *);


void func_L05_004DB540(Type1 *arg0) {
    if ((arg0->fAC->f410 != 0) && (func_L05_004DB948(arg0) != 0)) {
        func_L01_004E35D0(arg0);
    }
}
