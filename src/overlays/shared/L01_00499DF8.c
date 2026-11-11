#include "common.h"
typedef int u128 __attribute__((mode(TI)));
extern void func_L00_005E8188(s32, u128, s32, s32, s32, s32, f32, f32, f32);
void func_L01_00499DF8(void *object) {
    u8 *linked = *(u8 **)((u8 *)object + 0xAC);
    f32 y = *(f32 *)(linked + 0x24);
    f32 x = *(f32 *)(linked + 0x20);
    f32 quarterScale = *(f32 *)(linked + 0x38) * 0.25f;
    f32 average = (x + y) * 0.5f;
    func_L00_005E8188(*(s32 *)((u8 *)object + 0xB8), *(u128 *)((u8 *)object + 0x10),
                      1, 0, 1, 0, quarterScale * average,
                      *(f32 *)(linked + 0x3C), 1.0f);
}
