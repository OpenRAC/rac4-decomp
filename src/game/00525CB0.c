#include "common.h"

extern s32 D_0021EDD4;
extern s8 *D_0021DFF0;
extern u8 *D_0021DFE8;
extern s32 D_0021DE10;
extern s32 func_00526DC0(s32, s32);
extern void func_00526F20(s32, s32);
extern void func_00526FD8(s32, s32, s32);

void func_00525CB0(s32 a0)
{
    s32 result;
    s32 counter;

    if (D_0021EDD4 != 1) {
        return;
    }
    if (func_00526DC0(a0, 0) == 0) {
        func_00526F20(a0, 0);
        return;
    }
    if (func_00526DC0(a0, 2) == 0 && func_00526DC0(a0, 3) == 0) {
        func_00526FD8(a0, 2, 3);
        return;
    }
    if (func_00526DC0(a0, 1) == 0) {
        func_00526F20(a0, 1);
        return;
    }
    result = func_00526DC0(a0, 4);
    counter = D_0021DE10;
    if (result == 0 && D_0021DFF0[9] != 0) {
        func_00526F20(a0, 4);
        return;
    }
    counter = D_0021DE10;
    if (counter % 10 < 6) {
        if (func_00526DC0(a0, 5) == 0) {
            if (D_0021DFE8[0x1A9] != 2) {
                func_00526F20(a0, 5);
                return;
            }
        }
    }
    if (D_0021DE10 % 10 >= 6) {
        return;
    }
    if (func_00526DC0(a0, 0x14) != 0) {
        return;
    }
    if (D_0021DFE8[0x1A9] != 2) {
        func_00526F20(a0, 0x14);
    }
}
