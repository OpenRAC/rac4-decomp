/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_01EE38EC(s32 *arg0);
extern s32 func_01EE3960(void *arg0);
extern s32 func_01EE3A98(void *arg0);
extern s32 func_01EE3AC0(void *arg0);
extern void func_01F0C090(const char *, s32);
extern char D_0019C6B8[];

/* Finds the first entry in the chain of arg0 whose value fails the check against arg1; returns it, or 0. */
s32 func_01EF3470(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_v0;

    if (arg0 == 0) {
        func_01F0C090(D_0019C6B8, 0x149);
    }
    var_s0 = 0;
    if (func_01EE3AC0(arg0) != 0) {
        var_s0 = func_01EE3960(arg0);
    }
    var_v0 = 0;
    while (var_s0 != 0) {
        if (func_01EE3A98(var_s0) != 0 && func_0011A8A0(arg1, func_01EE3A98(var_s0)) == 0) {
            return var_s0;
        }
        var_s0 = func_01EE38EC(var_s0);
    }
    return var_v0;
}
