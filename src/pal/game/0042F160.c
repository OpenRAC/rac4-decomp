#include "common.h"

extern s32 D_003367B8[];

s32 func_004546C8(s16 arg0);
void func_004E2A48(s32 arg0);
void func_005275D8(s32 arg0, s32 arg1, s32 arg2);

void func_0042F160(void *arg0)
{
    s32 object;
    s32 value;
    s32 index;
    s32 result;

    result = 0;
    object = *(s32 *)((u32)arg0 + 0xAC);
    value = func_004546C8(*(s16 *)(object + 0x2B8));
    if (value != 0 && (s32)arg0 == *(s32 *)(value + 0x1C) &&
        *(u8 *)(value + 0x10) != 0) {
        func_004E2A48(*(s32 *)(object + 0x2B8));
        *(s32 *)(object + 0x2B8) = -1;
    }
    index = *(s32 *)(object + 0x2B4);
    if (index >= 0) {
        result = D_003367B8[index];
    }
    if (result != 0) {
        func_005275D8(result, 0, 0);
    }
}
