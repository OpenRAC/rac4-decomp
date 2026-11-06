#include "common.h"

extern s32 D_0021E6A0;
extern s32 D_0021E6A4;
extern s32 D_0021DDB4;
extern s32 D_0021EBB0;
s32 D_0021EBB4 = 0;

/* Sets D_0021E6A0 and D_0021DDB4 to a, D_0021E6A4 to -2, and clears D_0021EBB4 and D_0021EBB0. */
void func_L00_005F53A0(s32 a) {
    D_0021DDB4 = a;
    D_0021E6A4 = -2;
    D_0021E6A0 = a;
    D_0021EBB4 = 0;
    D_0021EBB0 = 0;
}
