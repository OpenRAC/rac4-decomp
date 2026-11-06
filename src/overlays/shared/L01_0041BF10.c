#include "common.h"
s32 func_00453508(s32);                             /* extern */
s32 func_0046BDD0(void *);                      /* extern */

void func_L01_0041BF10(void *arg0) {
    s32 temp_s0;

    temp_s0 = (*(s32 *)((u8 *)(arg0) + 0xAC));
    if (func_00453508(temp_s0) == 0) {
        func_00453508(temp_s0 + 4);
        return;
    }
    func_0046BDD0(arg0);
}
