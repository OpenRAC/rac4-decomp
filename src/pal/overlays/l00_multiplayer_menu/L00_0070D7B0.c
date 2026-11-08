/* cflags: -Wuninitialized */
#include "common.h"

int D_00220AC8 = 0;
int D_00220ACC = 0;

void func_L00_0070D7B0(s32 arg0) {
    if (D_00220ACC != 0) {
        *(s32 *)((u8 *)D_00220ACC + 0x19C) = arg0;
    }
    D_00220ACC = arg0;
    if (D_00220AC8 == 0) {
        D_00220AC8 = arg0;
    }
}