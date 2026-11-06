/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00169CD4;
extern s32 func_01E9E198(s32, s32, s32, s32, s32, s32, s32);

s32 func_01ED5DD0(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    return func_01E9E198(0x40, D_00169CD4, 0xFFFF, arg0, arg1, arg2, arg3);
}
