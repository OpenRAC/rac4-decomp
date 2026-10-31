#include "common.h"

/* when arg0 is 1 and the word at +4 of D_21D940 is set, runs func_00159570; on zero stores arg0 at +0x30, otherwise sets bit 8 of the word at +8 */
extern u8 D_21D940[];
s32 func_00159570();

void func_00163448(s32 arg0) {
    u8 *var_s0;

    if (arg0 == 1) {
        var_s0 = D_21D940;
        if (*(s32 *)(var_s0 + 4) != 0) {
            if (func_00159570() != 0) {
                *(s32 *)(var_s0 + 8) = *(s32 *)(var_s0 + 8) | 8;
            } else {
                *(s32 *)(var_s0 + 0x30) = arg0;
            }
        }
    }
}
