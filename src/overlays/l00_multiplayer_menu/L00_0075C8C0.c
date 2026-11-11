#include "common.h"

extern u8 *D_0021DFE8;
s32 func_L00_0075C8C0(const u8 *object,s32 index)
{
    s32 value=*(const s32 *)((u32)object+((u32)index<<2)+0x270U);
    if(value<0 || D_0021DFE8==0 ||
       *(u8 *)((u32)D_0021DFE8+(u32)value+0x104U)==255)value=-1;
    return value;
}
