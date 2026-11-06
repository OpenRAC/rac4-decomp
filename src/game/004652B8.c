#include "common.h"
extern int D_00171950[], D_0021DADC;
extern unsigned char D_0021EE18;
extern void func_00464AF8(int);
void func_004652B8(void)
{
    int a = D_00171950[0];
    if (a != 2)
        func_00464AF8(4);
    else if (D_0021DADC == a) {
        if (D_0021EE18)
            func_00464AF8(27);
        else
            func_00464AF8(14);
    } else if (D_0021DADC == 1)
        func_00464AF8(16);
}
