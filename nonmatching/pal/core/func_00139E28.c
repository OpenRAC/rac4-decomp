/* Not matching yet on PAL: SIZE ours 120 / disc 152 (tools/check_func.py --version pal func_00139E28 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"
extern s32 func_0012D420(void);
extern s32 func_0012D470(void);
extern u32 D_1000F520;
extern u32 D_1000F590;
extern u32 D_1000E000;
u32 func_00139E28(u32 *channel)
{
    s32 enabled = func_0012D420();
    u32 mask = D_1000F520;
    u32 previous;
    if (!(mask & 0x10000u))
        D_1000F590 = mask | 0x10000u;
    (void)D_1000E000;
    previous = *channel;
    *channel = previous & ~0x100u;
    D_1000F590 = mask;
    if (enabled)
        func_0012D470();
    return previous;
}
