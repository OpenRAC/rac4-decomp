/* Not matching yet: PAL WIP; main .text 0x00522410, 156B. Not part of the build. */
/*
 * Actual count clamp/register roles differ; six output-word stores are scheduled in a different
 * order from native. No source/effect or exactness approval is implied.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 14dde15bff94d3a51e3a4ff15339d2dfd63ef2021f16f927fd4ad50743f6c393
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00522410 nonmatching/pal/game/func_00522410.c --diff
 */
#include "common.h"

void func_00522410(void *object)
{
    s32 count, index;
    s32 *history;
    s32 first, second, third;
    s32 value25CC, value25D4, value370, value25D8, value25DC;

    index = *(s32 *)((u8 *)object + 0x264C);
    if (index >= 8)
        index = 7;
    index = (s32)((u32)index - 1U);
    if (index >= 0) {
        history = (s32 *)object;
        do {
            s32 word = (s32)((u32)index + (0x2630U / 4U));
            first = history[(s32)((u32)word - 17U)];
            second = history[(s32)((u32)word - 9U)];
            third = history[(s32)((u32)word - 1U)];
            history[(s32)((u32)word - 16U)] = first;
            history[(s32)((u32)word - 8U)] = second;
            history[word] = third;
            index = (s32)((u32)index - 1U);
        } while (index >= 0);
    }

    count = *(s32 *)((u8 *)object + 0x264C);
    value25CC = *(s32 *)((u8 *)object + 0x25CC);
    count = (s32)((u32)count + 1U);
    value25D4 = *(s32 *)((u8 *)object + 0x25D4);
    value370 = *(s32 *)((u8 *)object + 0x370);
    value25D8 = *(s32 *)((u8 *)object + 0x25D8);
    value25DC = *(s32 *)((u8 *)object + 0x25DC);
    *(s32 *)((u8 *)object + 0x264C) = count < 9 ? count : 8;
    *(s32 *)((u8 *)object + 0x25E4) = value25D8;
    *(s32 *)((u8 *)object + 0x25E8) = value25DC;
    *(s32 *)((u8 *)object + 0x25EC) =
        *(s32 *)((u8 *)object + 0x25D8) = value25CC;
    *(s32 *)((u8 *)object + 0x260C) =
        *(s32 *)((u8 *)object + 0x25DC) = value25D4;
    *(s32 *)((u8 *)object + 0x262C) =
        *(s32 *)((u8 *)object + 0x25E0) = value370;
}
