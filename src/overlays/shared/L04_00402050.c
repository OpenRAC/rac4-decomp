#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005E4118();

// Spawn object 0x24C9 as a copy of this one, scaling its float by the ratio of their linked floats.
void func_L04_00402050(u8 *obj) {
    u8 *n = func_L00_005DD000(0x24C9, 0);
    if (n != 0) {
        u8 *link;
        *(u16 *)(n + 0x32) = *(u16 *)(obj + 0x32);
        *(u8 *)(n + 0x31) = 1;
        link = *(u8 **)(n + 0x24);
        *(s64 *)(n + 0x38) = *(s64 *)(obj + 0x38);
        *(u128 *)(n + 0x10) = *(u128 *)(obj + 0x10);
        *(u128 *)(n + 0xF0) = *(u128 *)(obj + 0xF0);
        *(f32 *)(n + 0x70) = *(f32 *)(link + 0x24) * *(f32 *)(obj + 0x70) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
        func_L00_005E4118(n);
    }
}
