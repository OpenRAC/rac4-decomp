#include "common.h"
typedef struct {
    char pad[8];
    int mode;
    char padC[0x1D8];
    int flag;
} State;
extern State D_001719C8[];
extern int D_0021DB5C;
extern void func_00465338(int);
void func_00466268(void)
{
    int a = D_001719C8[0].mode;
    if (a != 2) {
        if (D_001719C8[0].flag)
            func_00465338(3);
        else
            func_00465338(4);
    } else if (D_0021DB5C == a)
        func_00465338(18);
    else if (D_0021DB5C == 1)
        func_00465338(29);
}
