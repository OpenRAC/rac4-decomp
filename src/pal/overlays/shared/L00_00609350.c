#include "common.h"
/* Keep the pre-store word and use an early exit; the two reset fields do not overlap. */
void func_L00_00609350(void *object,s32 value){
    s32 previous=*(s32 *)((u8 *)object+0x568);
    s32 difference=(s32)((u32)value-(u32)previous);
    if(difference<=0){*(s32 *)((u8 *)object+0x568)=value;return;}
    *(s32 *)((u8 *)object+0x568)=value;
    *(s32 *)((u8 *)object+0x34C)=0;
    *(s32 *)((u8 *)object+0x350)=0;
}
