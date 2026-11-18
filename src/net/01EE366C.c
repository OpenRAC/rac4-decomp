/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_0011AB04(u8 *);
extern void *func_01EE3600(void *, s32);
extern void *func_01EE3DB0(s32, s32);
extern s32 func_01EE3E9C(s32, s32, s32, u8 *, s32);

/* Appends arg2 bytes of arg1 (its strlen when arg2 is 0) to the string entry of arg0, creating the entry when it is missing. */
void *func_01EE366C(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_s1 = arg2;
    u8 *var_s0;
    void *temp_v0;
    s32 pool;

    if (arg0 == NULL || arg1 == NULL) {
        return NULL;
    }
    if (var_s1 == 0) {
        var_s1 = func_0011AB04(arg1);
    }
    var_s0 = *(u8 **)(arg0 + 0xC);
    if (var_s0 != NULL && *(s32 *)(var_s0 + 0x1C) == 3) {
        *(s32 *)(var_s0 + 0x28) = func_01EE3E9C(*(s32 *)(arg0 + 0x20), *(s32 *)(var_s0 + 0x28), *(s32 *)(var_s0 + 0x2C), arg1, var_s1);
        *(s32 *)(var_s0 + 0x2C) += var_s1;
    } else {
        var_s0 = func_01EE3600(arg0, 0);
        if (var_s0 == NULL) {
            return NULL;
        }
        pool = *(s32 *)(arg0 + 0x20);
        *(s32 *)(var_s0 + 0x1C) = 3;
        temp_v0 = func_01EE3DB0(pool, var_s1 + 1);
        *(void **)(var_s0 + 0x28) = temp_v0;
        if (temp_v0 == NULL) {
            return NULL;
        }
        func_0011A370(temp_v0, arg1, var_s1);
        *(u8 *)(*(u8 **)(var_s0 + 0x28) + var_s1) = 0;
        *(s32 *)(var_s0 + 0x2C) = var_s1;
    }
    return var_s0;
}
