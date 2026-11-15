/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/global_00222894.h"
extern u8 *D_002228B0;
s32 func_L41_00446EA0(void *, s32);

s32 func_L41_00446AA8(void *arg0, u8 *arg1)
{
    u8 *current = D_00222894;
    s32 result = 0, index = 0;
    while (current != D_002228B0) {
        if (current == arg1) {
            result = func_L41_00446EA0(arg0, index);
            break;
        }
        index++;
        current += 0x100;
    }
    return result;
}
