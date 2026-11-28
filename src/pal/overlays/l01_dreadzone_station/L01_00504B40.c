#include "pal/object_data.h"

u32 D_L01_00222794 = 0x6F107C10;
u32 D_L01_00222798 = 0x7F207C20;
f32 D_L01_0022279C = 0.0f;
f32 D_L01_002227A0 = 160.0f;
f32 D_L01_002227A4 = 200.0f;

extern f32 func_00454158(f32 angle);
extern u32 func_00454480(u32 from, u32 to, f32 blend);
extern f32 func_00472EB8(f32 low, f32 high);
extern f32 func_00454328(f32 angle, f32 step);
extern void func_004536B8(const f32 *position, s32 texture, u32 color, s32 style,
                          f32 size, f32 depth, f32 rotation);

void func_L01_00504B40(u8 *object) {
    const f32 *state = (const f32 *)((PalObject *)object)->data;
    f32 blend = func_00454158(D_L01_0022279C) * 0.5f + 0.5f;
    u32 color = func_00454480(D_L01_00222794, D_L01_00222798, blend);
    f32 wobble = func_00472EB8(D_L01_002227A0, D_L01_002227A4);
    const f32 *position = (const f32 *)(object + 0x10);

    D_L01_0022279C = func_00454328(D_L01_0022279C, wobble * 0.017453292f * 0.020000001f);
    func_004536B8(position, 0x43, color, 1, 1.0f, -0.1f, state[0]);
    func_004536B8(position, 0x31, 0x7FFFFFFF, 1, 0.3f, 0.0f, -state[1]);
    func_004536B8(position, 0x4B, 0x7F7F7F10, 3, 0.75f, 0.025f, -state[0]);
}
