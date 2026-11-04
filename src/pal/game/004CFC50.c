#include "common.h"

extern u8 D_0030F820[];
extern s32 D_00221A60;

s32 func_00506BB8(void);
s32 func_004A2798(void *arg0, s32 arg1);
s32 func_0045E850(s32 arg0);
s32 func_005062D0(s32 arg0, s32 arg1);

void func_004CFC50(void)
{
    s32 object;
    s32 auxiliary;
    s32 index;
    s32 pointer;
    s32 value;
    s32 first;
    s32 second;
    s32 third;

    object = (s32)(D_0030F820 + func_00506BB8() * 0x103C);
    auxiliary = object + 0xF90;
    index = *(s32 *)(auxiliary + 0x54);
    if (index < 0) {
        pointer = 0;
    } else {
        pointer = *(s32 *)(auxiliary + 0x34) + index * 0x18;
    }
    value = *(s32 *)(pointer + 8);
    first = func_004A2798(&D_00221A60, 0x10);
    second = func_0045E850(*(s32 *)(value + 8));
    third = func_005062D0(first, second);
    first = func_004A2798(&D_00221A60, 0x13);
    func_005062D0(first, value + 0xD);
    *(s32 *)(object + 8) &= -3;
}
