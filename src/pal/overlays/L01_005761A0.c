#include "common.h"

extern u8 D_0024F220[];

/* Update the first of two slots whose current intensity is lower. */
void func_L01_005761A0(void *descriptor, void *sample)
{
    u8 *slot = D_0024F220;
    s32 i;

    for (i = 0; i < 2; i++, slot += 4) {
        u16 id = *(u16 *)((u8 *)sample + 0x14);
        f32 distance = *(f32 *)((u8 *)sample + 0xC);
        f32 strength = *(f32 *)((u8 *)descriptor + 0x18);
        f32 weight = *(f32 *)((u8 *)sample + 8);
        f32 intensity = strength * weight;
        u8 *record = slot + id * 0x30;

        if (0.0f < distance && (f32)record[3] < intensity) {
            f32 x = *(f32 *)sample;
            s32 intensityWord = (s32)intensity;
            f32 scale;

            record[0] = (u8)(s32)((x + 32.0f) * 3.96f);
            record[1] = (u8)(s32)((*(f32 *)((u8 *)sample + 4) + 32.0f) * 3.96f);
            scale = *(f32 *)((u8 *)descriptor + 0x14);
            record[3] = (u8)intensityWord;
            record[2] = (u8)(s32)(scale * 31.875f);
            return;
        }
    }
}
