/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_00121FA0(s8 *arg0, s8 *arg1);
extern s32 func_01EE3A18(s32,void *);
extern void func_01F0C090(const char *, s32);
extern char D_0019C6B8[];
extern char D_0019C6D8[];
extern char D_0019C6E0[];
extern char D_0019C6E8[];

/* parses a name string into a mode value 1/0/2 */
s32 func_01EF31D0(s32 arg0, s32 arg1, s32 *arg2) {
    s8 *var_v0;

    var_v0 = (s8 *)func_01EE3A18(arg0, (void *)arg1);
    if (var_v0 != 0) {
        if (func_00121FA0(var_v0, D_0019C6D8) == 0) {
            *arg2 = 1;
            return 1;
        }
        if (func_00121FA0(var_v0, D_0019C6E0) == 0) {
            *arg2 = 0;
        } else if (func_00121FA0(var_v0, D_0019C6E8) == 0) {
            *arg2 = 2;
        } else {
            func_01F0C090(D_0019C6B8, 0xCD);
            return 0;
        }
        return 1;
    }
    return 0;
}
