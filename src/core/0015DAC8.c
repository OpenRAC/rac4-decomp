#include "common.h"

extern s32 func_0011EF60(s32 arg0);
extern void func_00120378(s32 arg0);
extern s32 D_0021DFC8;
/* Fill a state block, publish its derived value, and allocate. */
void *func_0015DAC8(s32 arg0)
{
    s32 buf[0xC];
    func_00120378((s32)buf);
    D_0021DFC8 = buf[7] + arg0;
    return (void *)func_0011EF60(arg0);
}
