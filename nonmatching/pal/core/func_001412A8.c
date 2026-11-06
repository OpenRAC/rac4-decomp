/* Not matching yet on PAL: SIZE ours 76 / disc 80 (tools/check_func.py --version pal func_001412A8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"

extern void func_00141108(void *decoder);
extern void func_00141140(void *decoder, s32 bits);
extern u32 D_10002020;

void func_001412A8(void *decoder)
{
    s32 bits;
    func_00141108(decoder);
    bits = (0U - (D_10002020 & 7U)) & 7U;
    if (bits != 0)
        func_00141140(decoder, bits);
}
