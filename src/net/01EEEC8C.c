/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type1 {
    char _p0[0x90];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
};
struct Type2 {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    void *f10;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

void func_01EEEC8C(s32 arg0, Type2 *arg1) {
    if (arg1->f0 == NULL || arg1->f4 == NULL || arg1->f8 == NULL || arg1->fC == NULL || arg1->f10 == NULL) {
        func_01F0C090(D_0019C400, 0x1FF);
    }
    D_0016E430->f90 = (s32)arg1->f0;
    D_0016E430->f9C = (s32)arg1->fC;
    D_0016E430->f98 = (s32)arg1->f8;
    D_0016E430->f94 = (s32)arg1->f4;
    D_0016E430->fA0 = (s32)arg1->f10;
}
