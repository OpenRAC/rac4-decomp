/* cflags: @ee29 */
#include "common.h"
s32 func_L00_00717030(const u8 *object,s32 index)
{
    if(index>=*(const s32 *)(object+0x120))return 0;
    return *(const s32 *)((u32)object+((u32)index<<2)+0x124U);
}
