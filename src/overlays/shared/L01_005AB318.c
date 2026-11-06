#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void func_L00_005F53C8(u8 *, u128, s32, f32, f32);

void func_L01_005AB318(u8 *arg0, f32 x) {
    func_L00_005F53C8(arg0, *(u128 *)(arg0 + 0x10), 0, 0.0f, x);
}
