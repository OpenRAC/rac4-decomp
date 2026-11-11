/* cflags:  */
#include "common.h"

s32 func_L11_003FE6D0(s32 arg0);
s32 D_00220EA0 = 0;

s32 func_L11_003FEB88(void)
{
    s32 i;
    s32 result;

    for (i = D_00220EA0; i; i = *(u32 *)(result + 100)) {
        func_L11_003FE6D0(i);
        result = *(s32 *)(i + 172);
    }
    return result;
}
