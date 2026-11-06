#include "common.h"
typedef struct {
    char pad[8];
    int mode;
    char padC[0x1D8];
    int flag;
} State;
extern State D_00171948[];
extern int D_0021DADC;
extern void func_00464AF8(int);
void func_00465A20(void)
{
    int a = D_00171948[0].mode;
    if (a != 2) {
        if (D_00171948[0].flag)
            func_00464AF8(3);
        else
            func_00464AF8(4);
    } else if (D_0021DADC == a)
        func_00464AF8(18);
    else if (D_0021DADC == 1)
        func_00464AF8(29);
}
