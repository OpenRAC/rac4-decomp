/* Not matching yet: PAL WIP; main .text 0x00410A40, 184B. Not part of the build. */
/*
 * h02 has49instructions versus native46: two initial DSLL32/DSRA32 parity-boolean canonicalizers
 * (+30/+34) and one final a0->v0 statuscopy (+A0) are the three extra instructions. Initialmask is
 * ANDI rather than nativeANDwithmask; initial weight/mask/accum setup order/registercolors differ.
 * Outpointer captured earlier, error107 formed in branchdelay/a0 rather than initialv0, prologue
 * same40frame/saves but reordered. Cor
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: c99f386e9473a6cd7984d3d9d3897f0452d4d5eb7f5cb8c917ef01d25bb7129f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00410A40 nonmatching/pal/game/func_00410A40.c --diff
 */
#include "common.h"

s32 func_00410A40(void *header, s64 *out)
{
    s32 rounds;
    s32 result = 0x107;
    u64 input = **(u64 **)((u8 *)header + 8);
    u64 weight;
    u64 mask;
    u64 accumulator;

    if (input & (u64)1) {
        mask = 3;
        weight = 2;
        rounds = 0x3D;
        accumulator = ((input & mask) > weight) ? mask : 1;
        do {
            weight *= 2;
            mask |= weight;
            rounds -= 1;
            accumulator = (weight < ((input * accumulator) & mask)) ?
                          (accumulator + weight) : accumulator;
        } while (rounds >= 0);
        result = 0;
        *(u64 *)out = ~accumulator + (u64)1;
    }
    return result;
}
