#include "common.h"

extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005E4118(void *);
typedef int u128 __attribute__((mode(TI)));

/* Allocates an object of kind 0x2125, copies fields from arg0 into it and links it back to arg0. */
u8 *func_L05_004F2D88(u8 *arg0) {
    u8 *s0;
    u128 hi;
    u16 a1;
    u16 a2;

    s0 = func_L00_005DD000(0x2125, 0);
    if (s0 != NULL) {
        *(u8 *)(s0 + 0x30) = *(u8 *)(arg0 + 0x30);
        a2 = *(u16 *)(s0 + 0x74) | 7;
        a1 = *(u16 *)(s0 + 0x34) | 0x104;
        *(u16 *)(s0 + 0x32) = *(u16 *)(arg0 + 0x32);
        *(u8 *)(s0 + 0x31) = *(u8 *)(arg0 + 0x31);
        *(s64 *)(s0 + 0x38) = *(s64 *)(arg0 + 0x38);
        *(u128 *)(s0 + 0x10) = *(u128 *)(arg0 + 0x10);
        hi = *(u128 *)(arg0 + 0xF0);
        *(u32 *)(s0 + 0xB8) = (u32)arg0;
        *(u128 *)(s0 + 0xF0) = hi;
        *(u16 *)(s0 + 0x74) = a2;
        *(u16 *)(s0 + 0x34) = a1;
        func_L00_005E4118(s0);
    }
    return s0;
}
