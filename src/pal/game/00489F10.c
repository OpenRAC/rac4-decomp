#include "common.h"
typedef struct Type1 {
    char p[0x50];
    short f50, f52;
    char q[0x74];
    short fC8, fCA;
} Type1;
extern Type1 D_002069D0[];
/* Reset both limits and their counters. */
void func_00489F10(void)
{
    D_002069D0[0].f50 = -32768;
    D_002069D0[0].f52 = 0;
    D_002069D0[0].fC8 = -32768;
    D_002069D0[0].fCA = 0;
}
