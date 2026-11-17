#include "common.h"

extern s32 func_004CA7F8();
extern void func_L01_004CA820(s32 arg0, s32 arg1);

// If func_004CA7F8 returns zero, call func_L01_004CA820 with the object and the low byte of the value, and store that byte at +0x2DD of the linked object.
void func_L01_004CF658(void *arg0, s32 arg1)
{
    u8 *linked = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 value = arg1 & 0xFF;

    if (func_004CA7F8() == 0) {
        func_L01_004CA820(arg0, value);
        linked[0x2DD] = value;
    }
}
