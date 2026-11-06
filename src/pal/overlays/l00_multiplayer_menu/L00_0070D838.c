#include "common.h"
extern u8 D_003E4F00[];
u8 *func_L00_0070D838(u32 index)
{
    u8 *result=0;
    if(index<0x39U)result=D_003E4F00+index*0x10U;
    return result;
}
