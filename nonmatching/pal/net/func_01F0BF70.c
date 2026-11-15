/* Not matching yet: 17/27 (62.96%) relocation-masked positional words; 108/108 candidate/target bytes. Wrapper return ABI and -O1 recipe remain unproved. Reproduce: python tools/check_func.py --version pal func_01F0BF70 nonmatching/pal/net/func_01F0BF70.c --diff. Not part of the build. */
/* cflags: -O1 -G8 -Wuninitialized */
#include "common.h"

/* 17/27 target words match (62.96%) under relocation-masked positional
 * comparison; 108/108 bytes. Comparison constants are scheduled differently.
 * The copy callee returns its destination pointer; the caller's return ABI
 * and this -O1 recipe remain hypotheses. Verify with
 * tools/diff_func.py --version pal func_01F0BF70. */
extern s32 func_0011AB04(char *);
extern char *func_0011A9EC(char *, char *);
s32 func_01F0BF70(char *arg0) {
    s32 len = func_0011AB04(arg0);
    s32 count = 0;
    s32 index = len - 1;
    s32 result = count < len;
    char *p;
    char c;
    do {
        count++;
        if (!result) break;
        p = arg0 + index;
        c = *p;
        index--;
        if (c == '/' || (result = count < len, c == '\\'))
            return (s32)func_0011A9EC(arg0, p + 1);
    } while (1);
    return result;
}

