#include "common.h"

void func_00452E98(const f32 *position,s32 texture,u32 color,s32 style,f32 size,f32 depth,f32 rotation);
f32 func_00453B10(f32 angle,f32 change);
f32 func_00472690(void);

void func_004363D0(void *arg0) {
    f32 *temp_s0;
    f32 temp_f0;
    void *temp_s1;

    temp_s1 = (*(void **)((s8 *)(arg0) + (0xAC)));
    temp_s0 = arg0;
    temp_f0 = func_00453B10((*(f32 *)((s8 *)(temp_s1) + (0x10))), 0.017453292f);
    (*(f32 *)((s8 *)(temp_s1) + (0x10))) = temp_f0;
    func_00452E98(temp_s0 + 4, 0x39, 0x40505050U, 1, 0.5f, 0.08f, func_00453B10(temp_f0 * 2.5f, 0.0f));
    func_00452E98(temp_s0 + 4, 0x2A, 0x207F2040U, 1, 0.5f, 0.08f, func_00453B10(-(*(f32 *)((s8 *)(temp_s1) + (0x10))) * 1.5f, 0.0f));
    func_00452E98(temp_s0 + 4, 0x2C, 0x207F2040U, 1, 0.5f, 0.08f, func_00453B10((*(f32 *)((s8 *)(temp_s1) + (0x10))), 0.0f));
    func_00452E98(temp_s0 + 4, 0x31, 0x20FF7F00U, 1, 0.36f, 0.08f, (*(f32 *)((s8 *)(temp_s1) + (0x10))) * 0.5f);
    func_00452E98(temp_s0 + 4, 0x31, 0x20FF7FU, 1, 0.36f, 0.08f, (*(f32 *)((s8 *)(temp_s1) + (0x10))) * -0.5f);
    func_00452E98(temp_s0 + 4, 0x2F, 0x507F7F7FU, 1, 0.11f, 0.08f, func_00472690());
}
