/* Not matching yet: PAL WIP; main .text 0x00489398, 156B. Not part of the build. */
/*
 *  0x000C mov.s $f26, $f16 | mov.s $f26, $f17 0x0014 mov.s $f25, $f15 | mov.s $f25, $f16 0x001C
 * mov.s $f24, $f14 | mov.s $f24, $f15 0x0024 mov.s $f23, $f13 | mov.s $f23, $f14 0x002C mov.s
 * $f22, $f12 | mov.s $f22, $f13 0x0034 mov.s $f21, $f18 | mov.s $f21, $f12 0x0040 mov.s $f20, $f17
 * | mov.s $f20, $f18 0x0048 bnel $v1, $zero, . + 4 + (0x3 << 2) | beqz $v1, . + 4 + (0x9 << 2)
 * 0x004C swc1 $f20, 0xA8($v1) | addiu $v0, $ze
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 293c6052b27f7621ca14dac923e4be68b4463a664814b80d7e022bb630244ed4
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00489398 nonmatching/pal/game/func_00489398.c --diff
 */
#include "common.h"

extern void *func_00476ED0(void *object);

s32 func_00489398(void *object, f32 fparg0, f32 fparg1, f32 fparg2,
                  f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6)
{
    u8 *state;

    state = func_00476ED0(object);
    if (state != NULL) {
        *(f32 *)(state + 0xAC) = fparg6;
        *(f32 *)(state + 0xB0) = fparg0;
        *(f32 *)(state + 0xB4) = fparg1;
        *(f32 *)(state + 0x9C) = fparg2;
        *(f32 *)(state + 0xA0) = fparg3;
        *(f32 *)(state + 0xA4) = fparg4;
        *(f32 *)(state + 0xA8) = fparg5;
        return 1;
    }
    return 0;
}
