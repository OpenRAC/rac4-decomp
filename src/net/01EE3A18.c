/* cflags: @ee296 -O2 -G8 */
#include "common.h"

extern s32 func_0011A8A0(void *arg0, const u8 *arg1);

/* Walks the list at arg0->0x10; returns 0x28 of the first node whose 0x24
   payload matches arg1, else 0. */
s32 func_01EE3A18(void *arg0, const u8 *arg1) {
    void *var_s0;
    s32 var_v0;

    if (arg0 == NULL) {
        return 0;
    }
    var_s0 = *(void **)((u8 *)arg0 + 0x10);
    while (var_s0 != NULL) {
        var_v0 = *(s32 *)((u8 *)var_s0 + 0x24);
        if (var_v0 != 0) {
            if (func_0011A8A0((void *)var_v0, arg1) == 0) {
                return *(s32 *)((u8 *)var_s0 + 0x28);
            }
        }
        var_s0 = *(void **)var_s0;
    }
    return 0;
}
