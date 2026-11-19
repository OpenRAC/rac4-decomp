#include "common.h"

extern int func_00547BB0(int a, int b);
extern unsigned char D_003DE2A8[];

void *func_00548D68(int arg0, int arg1)
{
    if (arg1 >= 0xA) {
        arg1 = 9;
        return (func_00547BB0(arg0, arg1) << 5) + D_003DE2A8;
    }
    return (func_00547BB0(arg0, arg1) << 5) + D_003DE2A8;
}
