/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB0];
    void *fB0;
    char _pB4[0x18];
    s32 fCC;
    s32 fD0;
};

s32 func_01EEE13C();
s32 func_01EF0550(s32, s32);
s32 func_01EF3748(void *);
extern s32 D_0016FF60[];
extern s32 D_00170358[];

void func_01EF7348(Type1 *arg0, s32 arg1) {
    arg0->fB0 = D_00170358;
    if (arg0->fCC != 0) {
        func_01EF0550(func_01EEE13C(), arg0->fCC);
        arg0->fCC = 0;
    }
    if (arg0->fD0 != 0) {
        func_01EF0550(func_01EEE13C(), arg0->fD0);
        arg0->fD0 = 0;
    }
    arg0->fB0 = D_0016FF60;
    if (arg1 & 1) {
        func_01EF3748(arg0);
    }
}
