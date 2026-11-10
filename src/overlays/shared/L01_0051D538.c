#include "common.h"

typedef struct {
    u8 pad[80];
    u8 *p50;
    u8 pad2[1036];
} Entry_3E6C58;
extern u8 D_00231810[];
extern Entry_3E6C58 D_00230280[];

void func_L01_0051D538(s32 idx, s32 flag, f32 a, f32 b)
{
    u8 *e = (u8 *)D_00230280 + idx * 0x470;
    u8 *p = *(u8 **)(e + 0x50);
    if (*(s16 *)(p + 134) == 0) {
        u8 *q = *(u8 **)(p + 112);
        u8 *r = q + 0x60;
        *(s16 *)(r + 0xFA) = 1;
        *(f32 *)(r + 0xD8) = b;
        if (flag) {
            u8 *f = (u8 *)D_00231810 + idx * 0xB0;
            u8 *s = *(u8 **)(f + 0x70);
            *(f32 *)(r + 0xD4) = *(f32 *)(s + 0x130) + a;
        } else {
            *(f32 *)(r + 0xD4) = a;
        }
    }
}
