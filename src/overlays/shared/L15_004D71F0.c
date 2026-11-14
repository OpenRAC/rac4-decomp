#include "common.h"

extern s32 func_L15_004D7108(s32);
extern s32 D_39FE50[];
extern u8 D_39AE50[];

// Finds the first word of D_39FE50 with a free bit, marks that bit used, and returns the 0x50-byte slot of D_39AE50 it names (NULL when all eight words are full).
void *func_L15_004D71F0(void) {
    void *var_lo = NULL;
    s32 *var_s1 = D_39FE50;
    s32 var_s0 = 0;
    s32 temp_a0;
    s32 temp_v0;

    do {
        temp_a0 = ~*var_s1;
        if (temp_a0 == 0) {
            var_s0 += 1;
            var_s1 += 1;
        } else {
            temp_v0 = func_L15_004D7108(temp_a0);
            *var_s1 |= 1 << temp_v0;
            var_lo = D_39AE50 + ((temp_v0 + (var_s0 << 5)) * 0x50);
            break;
        }
    } while (var_s0 < 8);
    return var_lo;
}
