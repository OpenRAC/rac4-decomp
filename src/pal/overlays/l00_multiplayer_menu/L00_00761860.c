#include "common.h"
/* Full native lookup; address arithmetic wraps in the target word width. */
extern u8 *D_0021E070;
s32 func_L00_00761860(const u8 *object,s32 index)
{
    s32 value=*(const s32 *)((u32)object+((u32)index<<2)+0x270U);
    if(value<0 || D_0021E070==0 ||
       *(u8 *)((u32)D_0021E070+(u32)value+0x104U)==255)value=-1;
    return value;
}
