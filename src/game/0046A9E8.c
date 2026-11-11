#include "common.h"

typedef struct {
    s32 field_0;
    s32 field_4;
    u8 field_8;
} B2Entry;

extern u8 D_001F87F0[];

s32 func_0054AB08(s32 arg0, s32 arg1);
void *func_0054A998(s32 arg0);
s32 func_0054AC58(s32 arg0);

void func_0046A9E8(s32 arg0, s32 arg1)
{
    if (*(s32 *)((u8 *)func_0054A998(func_0054AB08(arg0, arg1)) + 0x18) != 1) {
        ((B2Entry *)((arg0 - 1) % 0x14 * 0x304 + arg1 * 0xC + (s32)D_001F87F0))->field_8 |= 1;
    }
    if ((u8)func_0054AC58(func_0054AB08(arg0, arg1)) != 0) {
        ((B2Entry *)((arg0 - 1) % 0x14 * 0x304 + arg1 * 0xC + (s32)D_001F87F0))->field_8 |= 2;
    }
}
