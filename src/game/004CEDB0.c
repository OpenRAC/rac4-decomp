#include "common.h"

extern u8 D_0030F820[];
extern s32 D_00221960;

s32 func_00505B20(void);
s32 func_004A1A60(const s32 *arg0, s32 arg1);
const char *func_0045E038(s32 arg0);
s32 func_00505238(u32 arg0, const char *arg1);

void func_004CEDB0(void)
{
    s32 object;
    s32 auxiliary;
    s32 index;
    s32 pointer;
    s32 value;
    s32 first;
    const char *second;
    s32 third;

    object = (s32)(D_0030F820 + func_00505B20() * 0x103C);
    auxiliary = object + 0xF90;
    index = *(s32 *)(auxiliary + 0x54);
    if (index < 0) {
        pointer = 0;
    } else {
        pointer = *(s32 *)(auxiliary + 0x34) + index * 0x18;
    }
    value = *(s32 *)(pointer + 8);
    first = func_004A1A60(&D_00221960, 0x10);
    second = func_0045E038(*(s32 *)(value + 8));
    third = func_00505238(first, second);
    first = func_004A1A60(&D_00221960, 0x13);
    func_00505238(first, (const char *)(value + 0xD));
    *(s32 *)(object + 8) &= -3;
}
