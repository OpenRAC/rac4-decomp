/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_005262A8(void);
extern s32 func_00548240(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_L00_00526210(void *arg0);
extern s32 func_L00_00541648(s32, s32);

/* Returns the object held in *arg0 (or a new one from func_005262A8), releasing it when func_00548240 or func_L00_00541648 fails. */
void *func_L00_005418F8(void **arg0, s32 *arg1, s32 arg2)
{
    u8 *var_s0;
    s32 local[2];

    var_s0 = 0;
    if (arg0 != 0) {
        var_s0 = *arg0;
    }
    if (var_s0 == 0) {
        var_s0 = func_005262A8();
    }
    if (var_s0 != 0 && (func_00548240(*(s32 *)(var_s0 + 4), *arg1, arg2, local) != 0 || func_L00_00541648(*(s32 *)(var_s0 + 4), 0) != 0)) {
        if (arg0 == 0 || var_s0 != *arg0) {
            func_L00_00526210(var_s0);
        }
        var_s0 = 0;
    }
    if (arg0 != 0 && var_s0 != 0) {
        *arg0 = var_s0;
    }
    return var_s0;
}
