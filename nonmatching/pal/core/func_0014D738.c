/* Not matching yet: PAL WIP; main core.text 0x0014D738, 304B. Not part of the build. */
/*
 * Native entry DADDUa3,a1/state lifetime copy absent; candidate usesa1 directly and a3 forbin
 * vsnativet0. Entry/mask/constant/address instruction scheduling differs, though consumed
 * addresses nowuseSLL2.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f463b2d14fe8f394060157f36222b3276ec02156a80d4ffb0269838b94bc5e8c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0014D738 nonmatching/pal/core/func_0014D738.c --diff
 */
#include "common.h"

typedef struct DampingState DampingState;

void func_0014D738(u8 index, DampingState *state)
{
    u8 *bytes = (u8 *)state;
    u32 bin = (u32)index >> 3;
    f32 *entry = *(f32 **)bytes + bin;
    f32 total = ((*entry - 1.0f) * 0.96875f) + 1.0f;
    f32 weighted;
    f32 *cursor;
    s32 i;

    *entry = total;
    for (i = 0; i < (s32)bin; ++i) {
        entry = *(f32 **)bytes + i;
        *entry *= 0.96875f;
        total += (*(f32 **)bytes)[i];
    }
    for (i = (s32)bin + 1; i < 0x21; ++i) {
        entry = *(f32 **)bytes + i;
        *entry *= 0.96875f;
        total += (*(f32 **)bytes)[i];
    }

    *(f32 *)(bytes + 4) = 0.0f;
    cursor = *(f32 **)bytes;
    for (i = 0; i < 0x21; ++i) {
        f32 position = (f32)i;
        f32 value = *cursor;
        f32 previous = *(f32 *)(bytes + 4);
        cursor += 1;
        weighted = previous + ((position * value) / total);
        *(f32 *)(bytes + 4) = weighted;
    }
    *(s16 *)(bytes + 8) = 0;
    *(f32 *)(bytes + 4) = weighted * 8.0f;
}
