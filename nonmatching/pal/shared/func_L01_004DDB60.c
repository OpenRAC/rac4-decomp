/* Not matching yet: PAL WIP; level_01 .text 0x004DDB60, 116B. Not part of the build. */
/*
 * Tested ordinary graphs retain required accessed-memory effects but complete output still differs
 * in CFG/delay slots/return blocks/equality lowering. No useful new ordinary model identified now;
 * usefulness-based reprioritization, not a global compiler impossibility.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 8b92a73763fb43970bc65cc7a0483aa7a1d54f83c4f61819680a2aee87835266
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004DDB60 nonmatching/pal/shared/func_L01_004DDB60.c --diff
 */
#include "common.h"
#include "pal/mask_state.h"

typedef struct { u8 pad[0x594]; u8 f594[0x14]; u8 f5A8[0x14]; } Type1;
extern Type1 D_0038EAC0[];
extern s32 D_0021E8A4;

/* Ordered mode, payload, table and shared-state guards. */
s32 func_L01_004DDB60(void *arg0)
{
    s32 mode;
    u8 *payload;
    s32 index;
    s32 same;
    void *shared;
    u8 *entry;

    mode = D_0021E8A4;
    payload = *(u8 **)((u8 *)arg0 + 0xAC);
    if (mode != 1)
        return 1;
    index = *(s32 *)(payload + 8);
    if (index == 0xA)
        return 1;
    if (payload[5] == 0)
        return 1;
    entry = (u8 *)D_0038EAC0 + (u32)index;
    same = entry[0x59E] == mode;
    shared = D_0021E078;
    if (same != 0)
        return 1;
    if (*((s8 *)shared + 0x23) != 0 || *((s8 *)shared + 0xA) != 0)
        return 1;
    return 0;
}
