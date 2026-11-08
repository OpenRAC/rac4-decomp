/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x8];
    s32 f8;
};
struct Type1 {
    char _p0[0x80];
    Type2 *f80;
    char _p84[0x2C];
    void *fB0;
    char _pB4[0xC];
    s32 fC0;
    char _pC4[0x14];
    s32 fD8;
    char _pDC[0x4];
    s32 fE0;
};

s32 func_01EF0550(s32, s32);
s32 func_01EF0B14(s32, s32);
s32 func_01EF3748(void *);
extern s32 D_0016FF60[];
extern s32 D_00170F90[];

void func_01F0AC68(Type1 *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;

    arg0->fB0 = D_00170F90;
    temp_v0 = arg0->fD8;
    if (temp_v0 != 0) {
        func_01EF0B14(temp_v0, 3);
    }
    temp_v0_2 = arg0->fC0;
    if (temp_v0_2 != 0) {
        func_01EF0550(arg0->f80->f8, temp_v0_2);
    }
    temp_a1 = arg0->fE0;
    if (temp_a1 != 0) {
        func_01EF0550(arg0->f80->f8, temp_a1);
    }
    arg0->fB0 = D_0016FF60;
    if (arg1 & 1) {
        func_01EF3748(arg0);
    }
}
