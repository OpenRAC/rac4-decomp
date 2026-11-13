/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern char *func_01EE3A18(s32, s32);
extern s32 func_0011A8A0(char *, char *);
extern char *D_0016E5F0[];
s32 func_01F048C4(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    char *s = func_01EE3A18(arg1, arg2);
    s32 i;
    if (s != NULL) {
        for (i = 0; i < 0x3; i++) {
            if (func_0011A8A0(s, D_0016E5F0[i]) == 0) {
                *arg3 = i;
                return 1;
            }
        }
    }
    return 0;
}
