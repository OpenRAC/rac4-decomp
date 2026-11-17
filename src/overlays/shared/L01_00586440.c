#include "common.h"

extern void *func_L00_006F0C48(int a);
extern s32 D_26A518[];
s32 D_0021EBE0 = 0;

// Finds or allocates a two-word entry and stores arg0 and arg1 in it.
void func_L01_00586440(s32 arg0, s32 arg1) {
    s32 *e = func_L00_006F0C48(arg0);
    if (e == 0) {
        s32 n = D_0021EBE0;
        D_0021EBE0 = n + 1;
        e = D_26A518 + n * 2;
    }
    e[0] = arg0;
    e[1] = arg1;
}
