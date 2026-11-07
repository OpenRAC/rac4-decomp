/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
void func_01EEEDA0(u8 *object,void **a,void **b,s32 *count,void **c)
{
    s32 value=*(s32 *)(object+0x312C);
    void *first=object+0x30DC;
    void *second=object+0x30FC;
    void *third=object+0x311C;
    *a=first;
    *count=value;
    *b=second;
    *c=third;
}
