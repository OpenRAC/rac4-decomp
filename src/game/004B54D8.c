#include "common.h"

s32 func_004B5478();
s32 func_00501498(s32);
s32 func_00505AD8(s32);
s32 func_00505B20();
s32 func_00505C90(s32);
extern u8 D_00221770;

void func_004B54D8(void) {
    s32 temp_s0;

    if (D_00221770 == 0) {
        temp_s0 = func_00505B20();
        func_00505AD8(4);
        func_00501498(func_004B5478());
        func_00505C90(func_004B5478());
        func_00505AD8(temp_s0);
    }
    D_00221770 += 1;
}
