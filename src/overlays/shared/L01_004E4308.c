#include "common.h"

s32 func_L01_004E4358(void *object);
void func_00585D88(void *object);
void func_L01_00591BD8(void *object, s32 state, s32 arg);

void func_L01_004E4308(void *object)
{
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    s32 value;

    value = func_L01_004E4358(object);

    linked[0x76] = value;
    linked[0x75] = value;

    func_00585D88(object);
    func_L01_00591BD8(object, 1, -1);
}
