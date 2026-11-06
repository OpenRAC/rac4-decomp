#include "common.h"

extern void *func_0054A290(void *, s32);

f32 func_00549AB8(void *object)
{
    void *data = func_0054A290(object, 0);
    return *(f32 *)((u8 *)data + 0x48) * 0.0200000014f;
}
