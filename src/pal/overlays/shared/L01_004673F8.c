#include "common.h"
extern s32 func_004730F8(void *);

s32 func_L01_004673F8(void *object, s32 index)
{
    s32 *base;
    s32 *slot;
    s32 result;

    result = 0;
    base = (s32 *)((u8 *)*(void **)((u8 *)object + 0xAC) + 0x20);
    slot = base + index;
    if (func_004730F8((void *)*slot) == 0) {
        result = *slot;
    }
    return result;
}
