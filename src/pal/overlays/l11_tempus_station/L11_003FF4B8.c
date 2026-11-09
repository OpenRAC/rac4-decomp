/* cflags:  */
#include "common.h"

s32 func_L11_003FF000(s32 arg0);
s32 D_00220F50 = 0;

s32 func_L11_003FF4B8(void)
{
    s32 i;
    s32 result;

    for (i = D_00220F50; i; i = *(u32 *)(result + 100)) {
        func_L11_003FF000(i);
        result = *(s32 *)(i + 172);
    }
    return result;
}