#include "common.h"
extern s32 func_L01_0056E308(void *object);
extern s64 func_L01_0056D2D8(void *object, s32 kind);
s32 func_L01_00454C08(void *object);
s32 func_L01_00454C08(void *object)
{
    void *entry;
    void *current;
    s32 result;
    s32 empty;
    s32 ready;
    result = 0;
    entry = *(void **)((u8 *)object + 0xAC);
    current = entry;
    ready = func_L01_0056E308(current);
    current = entry;
    if (ready != 0) {
        empty = func_L01_0056D2D8(current, -1) == 0;
        result = empty;
    }
    empty = result;
    return empty;
}
