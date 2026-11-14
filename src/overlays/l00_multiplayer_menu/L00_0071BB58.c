#include "common.h"

extern void func_0069DF18(s32);
extern s32 D_004D76C0[];
s32 D_00220D6C = 0;

/* Steps the counter at D_00220D6C down by one and calls func_0069DF18 with the entry it now points at in D_004D76C0. */
void func_L00_0071BB58(void)
{
    s32 n;

    n = D_00220D6C - 1;
    D_00220D6C = n;
    func_0069DF18(D_004D76C0[n]);
}
