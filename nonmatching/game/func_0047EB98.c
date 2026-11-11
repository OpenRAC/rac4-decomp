/* Not matching yet: BYTES 1/20 - the OR operand order (regmove tie); delay slot fixed by -fno-delayed-branch (tools/try_func.py func_0047EB98 --diff). Not part of the build. */
/* cflags: -fno-delayed-branch */
#include "common.h"

/* Pack the two flags into the 0x36 halfword and report the packed value. */
s32 func_0047EB98(char *p, s32 a1, s32 a2)
{
    s32 v = (a1 << 11) | a2;

    *(u16 *)(p + 0x36) = v;
    return v;
}
