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

s32 func_L01_00468D48(void *);
s32 func_L01_004696B0(void *);
s32 func_L01_00469C88(void *);


void func_L01_00468B60(Type1 *arg0) {
    if ((arg0->fAC->f410 != 0) && (func_L01_00469C88(arg0) != 0)) {
        func_L01_00468D48(arg0);
        func_L01_004696B0(arg0);
    }
}
