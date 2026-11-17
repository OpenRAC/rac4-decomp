/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

void func_01F09DF0(s32);
void func_01F09E94(s32);

void func_01F09FB0(s32 arg0) {
    s32 temp_a0;
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;

    var_s0 = arg0;
    var_s1 = 4;
    var_a0 = var_s0;
    do {
        var_s1 -= 1;
        func_01F09DF0(var_a0);
        temp_a0 = var_s0;
        var_s0 += 8;
        func_01F09E94(temp_a0);
        var_a0 = var_s0;
    } while (var_s1 >= 0);
}
