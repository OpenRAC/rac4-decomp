/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct X X;
typedef struct { char _p0[0xC]; void (*fC)(X *, s32); } Vt;
struct X { char _p0[0x10]; Vt *f10; };
extern s32 D_0021D9B0;
s32 func_01EEE12C(void);
X *func_01EEE45C();
void func_01EED528(s32 a0) {
    X *x;
    if (D_0021D9B0 != 0) {
        return;
    }
    if (a0 == 0) {
        return;
    }
    D_0021D9B0 = a0;
    if (func_01EEE12C() == 0) {
        return;
    }
    x = func_01EEE45C();
    if (x == 0) {
        return;
    }
    x->f10->fC(x, a0);
}
