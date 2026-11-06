#include "common.h"

void func_004A0D78(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, s32 arg5);
void func_004A0F98(void *arg0, s32 arg1, f32 *arg2, f32 *arg3);

void func_004A13A0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4)
{
    f32 local0;
    f32 local1;
    f32 value;
    s32 offset;

    func_004A0D78(arg0, arg1, arg2, arg3, arg4, 0);
    func_004A0F98(arg0, *(s32 *)((u32)arg0 + 0x54), &local0, &local1);
    value = *arg2 - *arg4 * 0.5f;
    *arg2 = value;
    offset = *(s32 *)((u32)arg0 + 0x54) * 0x18;
    value += *(f32 *)((u32)arg0 + 0x5C) -
             *(f32 *)(offset + *(u32 *)((u32)arg0 + 0x34) + 0x10);
    *arg2 = value;
    *arg4 = local1;
}
