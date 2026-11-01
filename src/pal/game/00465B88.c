#include "common.h"

extern int D_0021DB64;
typedef struct Type1 {
    char p[0x10];
    int f10;
    char q[0x1B0];
    int f1C4;
    int f1C8;
    int f1CC;
    int f1D0;
    char r[0x10];
    int f1E4;
} Type1;
extern Type1 D_001719C8[];
extern void func_00465338(int);
/* Start the pending transition when its state and index permit it. */
void func_00465B88(void)
{
    if (D_001719C8[0].f1C4 == 2 && D_001719C8[0].f1CC < 0) {
        D_0021DB64 &= ~2;
        D_001719C8[0].f1CC = 9;
        D_0021DB64 &= ~16;
        D_001719C8[0].f1D0 = 0;
        func_00465338(17);
    }
}
