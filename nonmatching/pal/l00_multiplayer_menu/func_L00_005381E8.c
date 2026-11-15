/* Not matching yet: 13/14 (92.86%) relocation-masked positional words; 52/56 candidate/target bytes. Trailing word after return omitted; argument and callee types remain hypotheses. Reproduce: python tools/check_func.py --version pal func_L00_005381E8 nonmatching/pal/l00_multiplayer_menu/func_L00_005381E8.c --diff. Not part of the build. */
/* cflags: @ee29 -O2 -G0 -ffast-math -Wuninitialized */
#include "common.h"

extern long func_L00_00546BE8(unsigned long, long, long, long, long);

/* Forward the four arguments with a zero first argument. */
long func_L00_005381E8(long a, long b, long c, long d)
{
    return func_L00_00546BE8(0, a, b, c, d);
}
