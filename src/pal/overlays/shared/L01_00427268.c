#include "common.h"

void *func_00511CC0(s32 context);

s32 func_L01_00427268(void *object)
{
    s32 value;

    value = (s32)(*(f32 *)((u8 *)func_00511CC0(*(s32 *)((u8 *)*(void **)((u8 *)object + 0xAC) + 0x10)) + 0x2F24) * 0.1f);
    return value <= 0 ? 1 : value;
}
