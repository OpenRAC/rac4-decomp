#include "common.h"

extern s32 D_00172438[];
extern char D_003559E0[], D_003559C0[];
f32 D_002210D0 = 65.0f, D_002210D4 = 35.0f, D_002210D8 = 56.0f, D_002210DC = 51.0f;
u64 D_002210E0 = 0xFFFFFFFFFF696969ULL;
extern void func_00457E60(f32, f32, u64, const void *, f32, s32);
void func_0054E3E8(void)
{
    if (!D_00172438[0])
        func_00457E60(D_002210D8, D_002210DC, D_002210E0, D_003559E0, 1.0f, -1);
    func_00457E60(D_002210D0, D_002210D4, D_002210E0, D_003559C0, 1.0f, -1);
}
