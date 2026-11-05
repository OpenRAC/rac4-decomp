#include "common.h"
extern s32 func_00505B20(void);
extern void func_00505410(s32, f32);
extern void func_00504238(s32, f32, f32);
extern s32 D_221650;
extern u8 D_308108[];
void func_004A83A8(void) {
    s32 index = func_00505B20();
    u8 *entry = D_308108 + index * 0xB8;
    f32 value = *(f32 *)(entry + 0x30) * *(f32 *)(entry + 0x34);
    func_00505410(D_221650, value);
    func_00504238(D_221650, ((1.0f - value) * -0.3f) + 0.5f, 0.5f);
}
