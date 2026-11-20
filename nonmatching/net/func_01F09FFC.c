/* Not matching yet: BYTES 33/176 (tools/try_func.py func_01F09FFC --diff). Not part of the build. */
/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

s32 func_01F09CAC(s32 *arg0, s32 arg1);
void func_01F09D00(s32 *arg0, s32 arg1, s32 arg2);
s32 func_01F09EFC(char *arg0);
void func_01F0C090(char *arg0, s32 arg1);

extern s32 D_0019E5C0[];

void func_01F09FFC(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_s0;
    s32 var_s2;

    var_s0 = arg0;
    if ((arg1 == 0) || (arg2 == 0))
        func_01F0C090((char *)D_0019E5C0, 0x8F);
    var_s2 = 0;
    for (;;) {
        func_01F09CAC((s32 *)var_s0, arg1);
        var_s2 += 1;
        if (func_01F09EFC((char *)var_s0) != 0) {
            func_01F09D00((s32 *)var_s0, arg1, arg2);
            break;
        }
        var_s0 += 8;
        if (var_s2 >= 5) {
            func_01F0C090((char *)D_0019E5C0, 0xA5);
            break;
        }
    }
}
