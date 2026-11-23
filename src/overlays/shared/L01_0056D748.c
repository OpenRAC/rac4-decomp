#include "common.h"

typedef void (*fn_0056D748)(int, int);

int func_L01_0056D748(int *arg0, fn_0056D748 arg1, int arg2)
{
    int i;

    if (arg1 == 0) {
        return 0;
    }
    {
        fn_0056D748 cb = arg1;
        for (i = 0; i < arg0[0x10]; i++) {
            cb(arg0[i], arg2);
        }
    }
    return 1;
}
