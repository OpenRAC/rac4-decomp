/* Not matching yet: BYTES 12/176 (tools/try_func.py func_01F04538 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern char *func_00122160(char *searchee, char *lookfor);
extern void func_01F0435C(s32, s32, s32);
extern s32 D_0019E068[];

s32 func_01F04538(s32 arg0, char *arg1)
{
    char *p = arg1;
    char *s1;
    char *cur;
    char *q;
    char *r;
    s32 i;

    if (func_00122160(p, (char *)D_0019E068) != 0) {
        i = 0;
        while (i < 0x40) {
            i++;
            cur = p;
            q = func_00122160(cur, (char *)D_0019E068);
            if (q == 0)
                break;
            s1 = q + 0xE;
            *q = 0;
            r = func_00122160(s1, (char *)D_0019E068);
            *r = 0;
            func_01F0435C(arg0, (s32)cur, (s32)s1);
            p = r + 0xE;
        }
    }
    return 1;
}
