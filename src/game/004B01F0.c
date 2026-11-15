#include "common.h"

extern s32 func_00498DB0(s32 index);
s32 D_0021F770 = 0;

// Fetches records 0 and 1 from func_00498DB0 (falling back to D_0021F770) and swaps the two outputs when the order is wrong.
void func_004B01F0(u8 **arg0, u8 **arg1) {
    u8 *tmp;

    *arg0 = (u8 *)func_00498DB0(0);
    *arg1 = (u8 *)func_00498DB0(1);
    if (*arg1 == 0) {
        *arg1 = (u8 *)&D_0021F770;
    }
    if (((*arg1)[4] != 0 && (*arg0)[4] == 0) ||
        ((*arg0)[4] != 0 && (*arg1)[4] != 0 && *(s32 *)*arg1 < *(s32 *)*arg0)) {
        tmp = *arg0;
        *arg0 = *arg1;
        *arg1 = tmp;
    }
}
