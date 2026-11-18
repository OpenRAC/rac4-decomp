#include "common.h"

extern s32 *func_L00_00772168(s32 arg0);
extern void func_L00_00772D58(void *arg0, s32 arg1, s32 arg2, s32 arg3);

/* Looks up the slot for the given id, sends the message to it, and returns the slot's score field (or -1 if there is no slot) */
s32 func_L00_00771EE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 var_s0 = 0xFFFFFFFF;
    s32 *temp_v0;

    temp_v0 = func_L00_00772168(arg0);
    if (temp_v0 != 0) {
        func_L00_00772D58(temp_v0, arg1, arg2, arg3);
        var_s0 = temp_v0[1];
    }
    return var_s0;
}
