#include "common.h"

extern void func_L01_00591C58(u8 *object, s8 type);

void func_L01_00512968(u8 *object)
{
    u8 state = object[0x20];
    if (state == 1 || state == 4 || state == 5 || state == 6)
        func_L01_00591C58(object, 0);
}
