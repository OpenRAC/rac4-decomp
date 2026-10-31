#include "common.h"

extern void func_0046BDD0(s32);
extern void func_0046C7D0(void *, s32);
/* Calls func_0046C7D0 for each active entry in the table at arg0->unkAC (4 entries, 0x40 apart), then calls func_0046BDD0. */
void func_00415EC8(s32 *arg0) {
    s32 s3;
    s32 temp_v0;
    s32 var_s0;
    u8 *var_s1;

    s3 = 1;
    temp_v0 = arg0[0x2B];
    var_s0 = temp_v0 + 0xF0;
    var_s1 = (u8 *) temp_v0 + 0xF1;
    do {
        if (*var_s1 != 0) {
            func_0046C7D0(arg0, var_s0);
        }
        var_s0 += 0x40;
        s3 -= 1;
        var_s1 += 0x40;
    } while (s3 >= 0);
    func_0046BDD0(arg0);
}
