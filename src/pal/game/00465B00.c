#include "common.h"
extern int D_001719D0[], D_0021DB5C;
extern unsigned char D_0021EE98;
extern void func_00465338(int);
void func_00465B00(void)
{
    int a = D_001719D0[0];
    if (a != 2)
        func_00465338(4);
    else if (D_0021DB5C == a) {
        if (D_0021EE98)
            func_00465338(27);
        else
            func_00465338(14);
    } else if (D_0021DB5C == 1)
        func_00465338(16);
}
