#include "common.h"
typedef long long s128;

void func_0051CCC0(u8 *a0, s32 a1, f32 a2, f32 a3, f32 a4);

void func_0051C078(u8 *arg0) {
    f32 temp_f0;
    f32 temp_f13;
    f32 temp_f1;

    if (((*(u8 *)((s8 *)(arg0) + (0x266D))) == 0) || ((*(s16 *)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0x2EFC)))) + (0x50)))) + (0x86))) != 0x21)) {
        (*(f32 *)((s8 *)(arg0) + (0x17A0))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x2CE8)));
        (*(f32 *)((s8 *)(arg0) + (0x17A4))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x5FC)));
        (*(s128 *)((s8 *)(arg0) + (0x1790))) = (s128) (*(s128 *)((s8 *)(arg0) + (0x2CF0)));
        temp_f13 = *(f32 *)0x21DE74;
        temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x25C4)));
        func_0051CCC0(arg0, 0, temp_f13 * 0.042f * temp_f0, temp_f13 * 0.25f * temp_f0, *(f32 *)0x21DE7C * 19.198622f * temp_f0);
        temp_f1 = (*(f32 *)((s8 *)(arg0) + (0x17A8)));
        (*(f32 *)((s8 *)(arg0) + (0x62C))) = temp_f1;
        (*(f32 *)((s8 *)(arg0) + (0x5FC))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x17A4)));
        if (temp_f1 == 0.0f) {
            (*(u32 *)((s8 *)(arg0) + (0x60C))) = (*(u32 *)((s8 *)(arg0) + (0x60C))) + 1U;
            return;
        }
        (*(s32 *)((s8 *)(arg0) + (0x60C))) = 0;
    }
}
