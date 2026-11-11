/* Not matching yet: BYTES 1/116 (tools/try_func.py func_01EB3628 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern char *func_01EA90F0(s32 a0, s32 a1);
extern s32 func_01EB2EE0(s32 id);
extern void func_0011A370(char *dst, s32 src, s32 n);
extern void func_0011A518(char *p, s32 fill, s32 n);

/* Copy the 0x40-byte name of the looked-up entry into DST, or clear DST when the
   lookup fails. */
s32 func_01EB3628(s32 a0, s32 a1, char *dst)
{
    char *p = func_01EA90F0(a0, a1);

    if (dst != 0) {
        if (p != 0 && func_01EB2EE0(*(s32 *)(p + 0x2C)) == 0) {
            func_0011A370(dst, *(s32 *)(p + 0x2C), 0x40);
            return 0;
        }
        func_0011A518(dst, 0, 0x40);
    }
    return -1;
}
