#include "common.h"

extern s32 D_00222A90;
extern u8 D_00230380[];
extern s32 func_L01_005270B0(void *object);

void func_L01_00526FF8(void *object) {
    u8 *obj = object;
    u32 pool = (u32)D_00222A90;
    u32 index = (u32)*(s32 *)(obj + 0x94);
    s32 slot = *(s16 *)(obj + 0x84);
    u8 *linked = *(u8 **)((u8 *)pool + ((u32)slot << 5) + 0x1C);
    u8 *entry = D_00230380 + index * 0x470U;

    if (func_L01_005270B0(object) != 0) {
        linked[0x2C] = 1;
        entry[0x2B3] = 0;
        *(s16 *)(obj + 0x7E) = 2;
        *(f32 *)(D_00230380 + (u32)*(s32 *)(obj + 0x94) * 0x470U + 0x2D8) = 0.045f;
        *(f32 *)(D_00230380 + (u32)*(s32 *)(obj + 0x94) * 0x470U + 0x2C8) = 0.045f;
    }
}
