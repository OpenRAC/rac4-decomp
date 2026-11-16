/* Not matching yet: BYTES 100/192 (tools/try_func.py func_01F06034 --diff) (tools/try_func.py func_01F06034 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void func_01F0C090(void *, s32);
extern s32 D_0019E200;

s32 func_01F06034(u8 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_v1;
    s32 var_a1;
    s32 var_v0;
    u8 *var_a0;

    if (*(s32 *)(arg0 + 0x250) >= 0x65) {
        func_01F0C090(&D_0019E200, 0x273);
    }
    temp_a2 = *(s32 *)(arg0 + 0x258);
    var_v0 = 0;
    if (arg1 < temp_a2) {
        temp_a0 = arg1 * 4;
        if (*(s32 *)(temp_a0 + arg0 + 0xc0) != 0) {
            var_a1 = arg1;
            if (var_a1 < temp_a2 - 1) {
                var_a0 = (u8 *)(temp_a0 + arg0 + 0xc0);
                do {
                    var_a1 += 1;
                    *(s32 *)var_a0 = *(s32 *)(var_a0 + 4);
                    var_a0 += 4;
                } while (var_a1 < temp_a2 - 1);
            }
            temp_v1 = *(s32 *)(arg0 + 0x258);
            var_v0 = 1;
            *(s32 *)(temp_v1 * 4 + arg0 + 0xc0) = 0;
            *(s32 *)(arg0 + 0x258) = temp_v1 - 1;
        }
    }
    return var_v0;
}
