#include "common.h"
extern s32 D_00172378[];
s32 func_L01_004D30A0(u8 *arg0) {
    s32 r = 1;
    u8 *e = *(u8 **)(arg0 + 0xAC);
    s32 a, b;
    if ((*(u64 *)(arg0 + 0x30) & 0x104100000000ULL) != 0x4100000000ULL || *(s32 *)(arg0 + 0x98) != 0) {
        r = 0;
    }
    if (*(f32 *)(e + 0x50) > 0.0f) {
        r = 0;
    }
    a = *(s32 *)(e + 0x360);
    if (a > 0) {
        b = *(s32 *)(e + 0x364);
        if ((f32)b > 0.0f) {
            if (a >= D_00172378[0] - b) r = 0;
        } else {
            r = 0;
        }
    } else {
        r = 0;
    }
    return r;
}
