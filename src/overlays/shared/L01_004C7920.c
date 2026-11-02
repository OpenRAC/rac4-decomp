#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x3C0];
    s32 f3C0;
};
struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
};

s32 func_L01_004C7AC0(void *);
s32 func_L01_004C8070(void *);
s32 func_L01_004C80A8(void *);


void func_L01_004C7920(Type1 *arg0) {
    if ((arg0->fAC->f3C0 != 0) && (func_L01_004C80A8(arg0) != 0)) {
        func_L01_004C7AC0(arg0);
        func_L01_004C8070(arg0);
    }
}
