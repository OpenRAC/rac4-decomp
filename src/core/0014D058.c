/* cflags: -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

// Process arrays of floats with specific calculations
void func_0014D058(s32 arg0, s32 arg1) {
    f32 *var_a1;
    s32 var_a2;
    u32 calc;
    u32 var_a3;

    var_a1 = (f32 *)(arg1 + 0x3FC);
    var_a3 = 0xA280;
    var_a2 = 0xFF;

    do {
        var_a3 = (u32)var_a3 - 0xA2;
        calc = (u32)(((var_a3 >> 8) + 0x41) * (u32)var_a2);
        var_a2 -= 1;
        calc = (u32)((calc + 0xD1) >> 8);
        *var_a1 = *(f32 *)(((s32)(calc + 0x1D) << 2) + arg0);
        var_a1 -= 1;
    } while ((u32)var_a2 >= 0x57U);

    var_a3 = 0x457D;
    var_a2 = 0x57;

    do {
        var_a3 = (u32)var_a3 - 0xCB;
        var_a2 -= 1;
        *var_a1 = *(f32 *)((s32)((var_a3 >> 8) << 2) + arg0);
        var_a1 -= 1;
    } while (var_a2 != 0);
}
