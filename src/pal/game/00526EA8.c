#include "common.h"

extern s32 D_0021EE54;
extern s8 *D_0021E078;
extern u8 *D_0021E070;
extern s32 D_0021DE98;
extern s32 func_00527FB8(s32, s32);
extern void func_00528118(s32, s32);
extern void func_005281D0(s32, s32, s32);

void func_00526EA8(s32 a0)
{
    s32 result;
    s32 counter;

    if (D_0021EE54 != 1) {
        return;
    }
    if (func_00527FB8(a0, 0) == 0) {
        func_00528118(a0, 0);
        return;
    }
    if (func_00527FB8(a0, 2) == 0 && func_00527FB8(a0, 3) == 0) {
        func_005281D0(a0, 2, 3);
        return;
    }
    if (func_00527FB8(a0, 1) == 0) {
        func_00528118(a0, 1);
        return;
    }
    result = func_00527FB8(a0, 4);
    counter = D_0021DE98;
    if (result == 0 && D_0021E078[9] != 0) {
        func_00528118(a0, 4);
        return;
    }
    counter = D_0021DE98;
    if (counter % 10 < 6) {
        if (func_00527FB8(a0, 5) == 0) {
            if (D_0021E070[0x1A9] != 2) {
                func_00528118(a0, 5);
                return;
            }
        }
    }
    if (D_0021DE98 % 10 >= 6) {
        return;
    }
    if (func_00527FB8(a0, 0x14) != 0) {
        return;
    }
    if (D_0021E070[0x1A9] != 2) {
        func_00528118(a0, 0x14);
    }
}
