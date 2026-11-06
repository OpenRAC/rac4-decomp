#include "common.h"

extern void func_00453C68(void *object, f32 value, s32 mask);

void func_00498708(void *object)
{
    func_00453C68(object, 0.5f, (s32)0x80000000);
}
