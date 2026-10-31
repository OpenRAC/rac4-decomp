#include "common.h"

/* game: when arg0 is non-NULL and its byte at 0x558 is 0xFF, returns; otherwise clears eight 0x10-byte entries of D_003D6458 starting at (index << 7) + 0x70 */
extern u8 D_003D6458[];

void func_00438CD0(u8 *arg0) {
    s32 var_v1;
    s32 var_a1;
    u8 *var_v0;
    u8 temp;

    var_v1 = 0;
    if (arg0 != NULL) {
        temp = arg0[0x558];
        if (temp == 0xFF) {
            return;
        }
        var_v1 = arg0[0x54C] * 4 + temp;
    }
    var_v1 = (var_v1 << 7) + (s32)D_003D6458;
    var_v0 = (u8 *)var_v1 + 0x70;
    var_a1 = 7;
    do {
        *var_v0 = 0;
        var_a1 -= 1;
        var_v0 -= 0x10;
    } while (var_a1 >= 0);
}
