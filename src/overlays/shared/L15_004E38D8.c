#include "common.h"

extern void func_L00_005E99A0(f32, f32, f32);

void func_L15_004E38D8(u8 *arg0, f32 x, f32 y) {
    func_L00_005E99A0(x, y, *(f32 *)(*(u8 **)(arg0 + 0xAC) + 0x1C0));
}
