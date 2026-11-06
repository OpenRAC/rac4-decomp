#include "common.h"
typedef struct Type1 {
    char p[0x10];
    int f10;
    char q[0x1B0];
    int f1C4, f1C8, f1CC, f1D0;
} Type1;
extern Type1 D_00171948[];
extern int D_0021DAE4;
extern void func_00464AF8(int);
/* Begin the pending transition and clear its flags and counters. */
void func_00465118(void)
{
    if (D_00171948[0].f1C4 == 2 && D_00171948[0].f1CC < 0) {
        D_00171948[0].f1CC = 7;
        D_00171948[0].f10 = 0;
        D_0021DAE4 &= ~0x800;
        D_00171948[0].f1D0 = 0;
        func_00464AF8(13);
    }
}
