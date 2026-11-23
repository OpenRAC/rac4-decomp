/* Not matching yet: PAL WIP; main net.text 0x01EABAF8, 280B. Not part of the build. */
/*
 * Direct unsigned conversion and postcall0x640 repaired; 296B versus native280B. MTC1/CVT and loop
 * NOPs, symbol/base copies, and merged final store/return schedule remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 4706e9524896d2fc40d23dfb114c87dee7aaf43d3eec7cc225956cb19a9bf353
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EABAF8 nonmatching/pal/net/func_01EABAF8.c --diff
 */
#include "common.h"

typedef struct { s32 f0, f4, f8, fC; } G;
extern u8 D_00168BA1;
extern G D_001B23E8;
s32 func_01EABA88(void);
s32 func_01EABAE8(void);

s32 func_01EABAF8(void) {
    u32 tick;
    u32 delta;
    u32 remainder;
    u32 rounds;
    f32 scaled;
    s32 converted;

    if (D_00168BA1 == 0) {
        if (func_01EABA88() != 0) {
            return 0x640;
        }
    }

    tick = (u32)func_01EABAE8();
    delta = tick - (u32)D_001B23E8.fC;
    D_001B23E8.fC = (s32)tick;
    if (delta != 0) {
        remainder = (u32)D_001B23E8.f4 + delta;
        D_001B23E8.f4 = (s32)remainder;
        if (remainder > 0x11940000U) {
            rounds = (u32)D_001B23E8.f0;
            do {
                remainder -= 0x11940000U;
                rounds += 1U;
            } while (remainder > 0x11940000U);
            D_001B23E8.f0 = (s32)rounds;
            D_001B23E8.f4 = (s32)remainder;
        }

        scaled = (f32)(u32)D_001B23E8.f4 * 0.003390842f;
        converted = (s32)scaled;
        if (scaled >= 2147483648.0f) {
            converted = (s32)((u32)(s32)(scaled - 2147483648.0f) | 0x80000000U);
        }
        D_001B23E8.f8 = converted;
    }
    return 0;
}
