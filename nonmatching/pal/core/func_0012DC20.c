/* Not matching yet on PAL: BYTES 1/16 (1 words differ) (tools/check_func.py --version pal func_0012DC20 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"

extern u32 D_B0001020[];
extern void func_0012DB90(u32 *reg, u32 value);

void func_0012DC20(u32 value)
{
    func_0012DB90(D_B0001020, value);
}
