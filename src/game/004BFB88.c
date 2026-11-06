#include "common.h"

extern u8 D_0030B358[];

s32 func_00505B20(void);
void func_004BFC30(s32 arg0);
void func_004C04F8(s32 arg0);

void func_004BFB88(void)
{
    s32 object;
    s32 auxiliary;
    s32 index;
    s32 pointer;
    s32 argument;
    s32 value;

    object = (s32)(D_0030B358 + func_00505B20() * 0x258);
    auxiliary = object + 0x1EC;
    if (*(s32 *)(auxiliary + 0x50) > 0) {
        index = *(s32 *)(auxiliary + 0x54);
        if (index < 0) {
            pointer = 0;
        } else {
            pointer = *(s32 *)(auxiliary + 0x34) + index * 0x18;
        }
        argument = *(s32 *)(pointer + 8);
        value = *(s32 *)(argument + 8);
        if (value == 0) {
            func_004BFC30(argument);
        } else if (value == 1) {
            func_004C04F8(argument);
        }
    }
    *(s32 *)(object + 4) &= -5;
}
