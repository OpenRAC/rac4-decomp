#include "common.h"
typedef struct State {
    u8 p0[0x1C4];
    s32 screen;
    s32 p1C8;
    s32 menu;
} State;
extern State D_001719C8;
extern s32 D_0022118C, D_0021DAF8, D_002212CC;
f32 D_00220A10 = 0.0f;
extern void func_004492A8(s32);
extern void func_004E88B8(s32, u64, u64);
extern u64 func_004495D8(s32, s32);
extern void func_0044A728(s32, s32, s32, s32, s32, s32, s32, s32, u64, u64);
extern void func_0045F6A8(s32, s32, u64, f32, f32, f32, f32, f32);
extern void func_004493D8(void);
extern void func_0044A2A0(s32, s32, s32, s32);
void func_004F4670(void)
{
    s32 period;
    f32 angle;
    f32 size;
    if ((u32)D_001719C8.screen - 15U <= 1U || D_001719C8.menu == 15 || (D_0022118C != 0 && D_0021DAF8 >= 0)) {
        func_004492A8(1);
        period = 55;
        size = 272.0f;
        func_004E88B8(0x42, 0x8000000044UL, 0);
        func_004E88B8(0x47, 0x3004B, 0);
        func_0044A728(425, 250, 64, 64, 0, 0, 64, 64, 0x80808080UL, func_004495D8(3, 1));
        angle = (f32)(D_002212CC % period) * -6.2831854820251465f / (f32)period;
        func_0045F6A8(64, 64, func_004495D8(4, 1), 7312.0f, 4512.0f, size, size, angle);
        func_004493D8();
        if ((u32)D_001719C8.screen - 15U <= 1U || D_001719C8.menu == 15)
            D_0022118C = 25;
        else
            D_0022118C = (s32)((u32)D_0022118C - 1U);
    }
    func_004E88B8(0x42, 0x8000000044UL, 0);
    func_0044A2A0(0, 0, 0, (s32)(D_00220A10 * 128.0f));
}
