/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

typedef struct { s32 a; s32 b; } Pair;
extern s32 func_01EA0828(void *arg0, s32 arg1, Pair arg2, s32 arg3);
extern s32 func_01EA13B8(void *arg0, s32 arg1);
extern s32 func_01EA8BA0(Pair value);
extern s32 *D_00167EFC[];
extern u8 *D_00167F30[];
extern s32 D_00167F40[];

// Offers the request to the hook table at D_00167F30 first, then falls back to func_01EA0828 or func_01EA13B8; returns the first non-zero result.
s32 func_01EA1730(void *arg0, s32 arg1, Pair arg2, s32 arg3) {
    u8 **hook;
    s32 ret;
    s32 var_s3;
    s32 temp_a3;

    ret = func_01EA8BA0(arg2);
    if (ret == 0) {
        if (arg3 != 0) {
            var_s3 = 0;
            if (D_00167F40[0] != 0) {
                var_s3 = ((s32 *)D_00167F40[0])[33];
            }
            *(s32 *)((u32)arg0 + 0x45C) = *(s32 *)((u32)arg0 + 0x45C) + 1;
            hook = &D_00167F30[0];
            if (hook[0] == NULL || ((s32 (*)(void *))((s32 *)hook[0])[6])(arg0) == 0 || (ret = ((s32 (*)(void *, s32))((s32 *)hook[0])[4])(arg0, arg1)) == 0) {
                temp_a3 = D_00167EFC[0][8];
                ret = func_01EA0828(arg0, arg1, arg2, (temp_a3 == 0) ? var_s3 : temp_a3);
            }
        } else {
            hook = &D_00167F30[0];
            if (hook[0] == NULL || ((s32 (*)(void *))((s32 *)hook[0])[6])(arg0) == 0 || (ret = ((s32 (*)(void *, s32))((s32 *)hook[0])[5])(arg0, arg1)) == 0) {
                ret = func_01EA13B8(arg0, arg1);
            }
        }
    }
    return ret;
}
