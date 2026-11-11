/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A518(char *p, s32 fill, s32 n);

/* Register the counter block: clear 0x10 bytes, store the pair and bump the
   shared count; a null argument, a null counter or a small size reports 2.
   Early returns, so the 2 is live in $v0 from the first instruction the way
   retail has it (`addiu $v0,$zero,2`), instead of a single `r` local that
   GCC keeps in $v1 and copies at the exit. */
s32 func_01EB6168(char *p, s32 *q, u32 n)
{
    if (p == 0)
        return 2;
    if (q == 0)
        return 2;
    if (n < 9)
        return 2;

    func_0011A518(p, 0, 0x10);
    *(s32 *)(p + 8) = (s32)q;
    *(s32 *)p = n;
    (*q)++;
    return 0;
}
