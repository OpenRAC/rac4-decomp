#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005E4118(void *);

u8 *func_L01_00489B18(u8 *arg0) {
    u8 *s0 = func_L00_005DD000(0x2087, 0);
    if (s0 != NULL) {
        *(u8 *)(s0 + 0x30) = *(u8 *)(arg0 + 0x30);
        *(u16 *)(s0 + 0x32) = *(u16 *)(arg0 + 0x32);
        *(u8 *)(s0 + 0x31) = 1;
        *(s64 *)(s0 + 0x38) = *(s64 *)(arg0 + 0x38);
        *(u128 *)(s0 + 0x10) = *(u128 *)(arg0 + 0x10);
        *(u128 *)(s0 + 0xF0) = *(u128 *)(arg0 + 0xF0);
        *(u32 *)(s0 + 0xB8) = (u32)arg0;
        func_L00_005E4118(s0);
    }
    return s0;
}
