/* Not matching yet: PAL WIP; main core.text 0x0014BBE0, 232B. Not part of the build. */
/*
 * Actual initial table read/FP producer ordering and later read/predicate scheduling remain
 * different despite source capture statements.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 55c4e9f84df49e51bbb848c850312aa76aa88af938ebd0d77f818a250ea7ec01
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0014BBE0 nonmatching/pal/core/func_0014BBE0.c --diff
 */
#include "common.h"

extern f32 D_001A0218[];

s32 func_0014BBE0(f32 *values, f32 *output, f32 center, f32 floor)
{
    f32 initial;
    f32 lower;
    f32 upper;
    f32 maximum;
    f32 current;
    f32 *tableCursor;
    f32 *valueCursor;
    u32 index;
    u32 maximumIndex;
    s32 below;

    initial = D_001A0218[0];
    lower = center * 0.75f;
    below = initial < lower;
    upper = center * 1.333f;
    index = 0;
    tableCursor = D_001A0218;
    if (below) {
        do {
            tableCursor += 1;
            index += 1U;
        } while (*tableCursor < lower);
    }

    valueCursor = (f32 *)((u8 *)values + (index << 2));
    tableCursor = (f32 *)((u8 *)D_001A0218 + (index << 2));
    maximum = *valueCursor;
    maximumIndex = index;
    do {
        current = *valueCursor;
        if (maximum < current) {
            maximum = current;
            maximumIndex = index;
        }
        index += 1U;
        tableCursor += 1;
        valueCursor += 1;
    } while ((s32)index < 0x4A && *tableCursor <= upper);

    if (maximum < floor) {
        *output = (floor + maximum) * 0.5f;
    } else {
        *output = maximum;
    }
    return (s32)maximumIndex;
}
