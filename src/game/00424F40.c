#include "common.h"
s32 func_00424EC8(void *, s32);                 /* extern */
void func_00473A88(void *, s32, s32);    /* extern */

void func_00424F40(void *arg0) {
    f32 temp_f0;
    f32 temp_f20;
    s32 temp_a1;
    s32 var_s2;
    s32 var_s3;
    void *temp_v0;
    void *var_s0;

    var_s2 = 7;
    var_s3 = 1;
    temp_v0 = (*(void **)((u8 *)(arg0) + 0xAC));
    temp_f0 = (*(f32 *)((u8 *)(temp_v0) + 0x6C));
    var_s0 = temp_v0;
    temp_f20 = temp_f0 * temp_f0;
    do {
        temp_a1 = (*(s32 *)((u8 *)(var_s0) + 0));
        if (temp_a1 != 0) {
            var_s3 = 0;
            if ((*(f32 *)((u8 *)(var_s0) + 0x20)) < temp_f20) {
                func_00424EC8(arg0, temp_a1);
                (*(s32 *)((u8 *)(var_s0) + 0)) = 0;
            }
        }
        var_s2 -= 1;
        var_s0 += 4;
    } while (var_s2 >= 0);
    if (var_s3 != 0) {
        func_00473A88(arg0, 4, -1);
    }
}
