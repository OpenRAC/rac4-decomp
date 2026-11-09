/* cflags: -Wuninitialized */
#include "common.h"

int D_00220AC0 = 0;
int D_00220AC4 = 0;

void func_L00_0070D788(s32 arg0) {
    if (D_00220AC4 != 0) {
        *(s32 *)((u8 *)D_00220AC4 + 0x19C) = arg0;
    }
    D_00220AC4 = arg0;
    if (D_00220AC0 == 0) {
        D_00220AC0 = arg0;
    }
}