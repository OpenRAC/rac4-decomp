#include "common.h"

extern int D_0021EE54, D_0021EE58;
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
int D_0021F1D4 = 5;
extern void func_00465338(int);
/* Reset the state counters and select state four. */
void func_00465460(void)
{
    if (!D_0021EE54 && !D_0021EE58)
        D_001719C8[0].f1E4 = 0;
    D_001719C8[0].f10 = 0;
    func_00465338(4);
    D_0021F1D4 = 5;
}
