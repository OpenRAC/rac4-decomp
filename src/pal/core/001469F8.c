/* cflags: @ee29 */
#include "common.h"
s32 func_001469F8(s32 mode,s32 reserved)
{
    u32 result=0;
    switch(mode){
    case 0: while (*(volatile s32 *)0x10002010 < 0) {} result=0;break;
    case 1: result=*(volatile u32 *)0x10002010 >> 31;break;
    }
    return result;
}
