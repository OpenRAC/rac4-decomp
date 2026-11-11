#include "common.h"

typedef struct Type2 Type2;
typedef struct Type3 {
    char _p0[0x1C];
    void (*f1C)(Type2 *);
} Type3;

struct Type2 {
    char _p0[0x58];
    Type3 *f58;
};

typedef struct Type1 {
    char _p0[0xC];
    Type2 *fC;
    char _p10[0xAC - 0x10];
    s32 fAC;
    Type2 *fB0[1];
} Type1;

s32 D_00220D8C = 0;
u8 D_00220D90 = 0;

void func_00476080(s32 *, f32, f32);

void func_L00_0071F4F8(Type1 *arg0) {
    s32 i;

    if (arg0->fC != NULL) {
        arg0->fC->f58->f1C(arg0->fC);
    }
    if (D_00220D90 != 0) {
        func_00476080(&D_00220D8C, 0.0f, 0.0779220834f);
    } else {
        func_00476080(&D_00220D8C, 1.0f, 0.0779220834f);
    }
    for (i = 0; i < arg0->fAC; i++) {
        arg0->fB0[i]->f58->f1C(arg0->fB0[i]);
    }
}
