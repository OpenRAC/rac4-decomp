/* Not matching yet: 24/26 (92.31%) relocation-masked positional words; 104/104 candidate/target bytes. Two scheduling/register words differ; mapped callee signatures are used. Reproduce: python tools/check_func.py --version pal func_00503850 nonmatching/pal/game/func_00503850.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* 24/26 target words match (92.31%) under relocation-masked positional
 * comparison; 104/104 bytes. Two scheduling/register words differ.
 * Mapped callees use their matched source signatures. Verify with
 * tools/diff_func.py --version pal func_00503850. */
extern s32 func_00502448(s32 *);
extern char *func_00502738(char *, u32 *);
u32 func_00503850(void *arg0) {
    u32 sp0;
    u8 *p;
    u32 n;
    u32 result;
    p = (u8 *)func_00502738((char *)arg0, &sp0);
    result = (u32)p;
    if (p == 0) goto done;
    n = func_00502448((s32 *)p);
    n = func_00502448((s32 *)((u32)p + 4 + n * 4));
    if (n != 0) goto found;
    return 0;
found:
    result = n + (u32)arg0;
done:
    return result;
}

