/* Not matching yet on PAL: BYTES 15/52 (9 words differ) (tools/check_func.py --version pal func_0013EFD8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"

extern void func_0013EAE0(void *decoder);
extern u32 D_10002010;

void func_0013EFD8(void *decoder)
{
    if ((D_10002010 & 0x80004000U) == 0x80000000U)
        func_0013EAE0(decoder);
}
