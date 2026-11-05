/* cflags: @ee29 -O2 -G0 */
#include "common.h"
extern s32 func_0012D420(void);
extern s32 func_0012D470(void);
u32 func_00139E28(volatile u32 *channel)
{
    s32 enabled = func_0012D420();
    u32 mask = *(volatile u32 *)0x1000F520;
    u32 previous;
    if (!(mask & 0x10000u))
        *(volatile u32 *)0x1000F590 = mask | 0x10000u;
    (void)*(volatile u32 *)0x1000E000;
    previous = *channel;
    *channel = previous & ~0x100u;
    *(volatile u32 *)0x1000F590 = mask;
    if (enabled)
        func_0012D470();
    return previous;
}
