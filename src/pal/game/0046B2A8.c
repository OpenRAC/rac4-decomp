#include "common.h"

typedef struct {
    s32 field_0;
    s32 field_4;
    u8 field_8;
} B2Entry;

extern u8 D_001F8878[];

s32 func_0054C070(s32 arg0, s32 arg1);
void *func_0054BF00(s32 arg0);
s32 func_0054C1C0(s32 arg0);

void func_0046B2A8(s32 arg0, s32 arg1)
{
    if (*(s32 *)((u8 *)func_0054BF00(func_0054C070(arg0, arg1)) + 0x18) != 1) {
        ((B2Entry *)((arg0 - 1) % 0x14 * 0x304 + arg1 * 0xC + (s32)D_001F8878))->field_8 |= 1;
    }
    if ((u8)func_0054C1C0(func_0054C070(arg0, arg1)) != 0) {
        ((B2Entry *)((arg0 - 1) % 0x14 * 0x304 + arg1 * 0xC + (s32)D_001F8878))->field_8 |= 2;
    }
}
