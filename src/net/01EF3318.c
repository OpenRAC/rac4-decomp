/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(const char *, const char *);
extern s32 func_01EE3A18(void *arg0, const u8 *arg1);
extern s32 *D_0016E4A0[];

s32 func_01EF3318(s32 arg0, s32 arg1, s32 *arg2)
{
    char *v = (char *)func_01EE3A18((void *)arg0, (const u8 *)arg1);
    s32 i;

    if (v != 0) {
        for (i = 0; i < 9; i++) {
            if (func_0011A8A0(v, (const char *)D_0016E4A0[i]) == 0) {
                *arg2 = i;
                return 1;
            }
        }
    }
    return 0;
}
