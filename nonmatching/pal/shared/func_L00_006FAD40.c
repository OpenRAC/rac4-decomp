/* Not matching yet: PAL WIP; level_00 .text 0x006FAD40, 264B. Not part of the build. */
/*
 * SIX additional ANDI31 shiftcount masks at compiled6C/78/8C/DC/E0/100 plus one loopNOP account
 * for28B size difference. No native-only opcode counts. Registers, scalar scheduling and branch
 * offsets consequently differ. Full67 positional word differences preserved. This actual
 * count-mask materialization is the predeclared falsifier; masks stay for defined semantics.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: d01d5e851f59c54dbfb89002da06f6f47e9a3251ba5da730e0b8dc99a5609596
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_006FAD40 nonmatching/pal/shared/func_L00_006FAD40.c --diff
 */
#include "common.h"

s32 func_L00_006FAD40(u8 *stream, s32 *cursor, s32 request)
{
    s32 position = *cursor;
    s32 quotient = position / 8;
    s32 remainder = position - quotient * 8;
    u8 *byte = stream + quotient;
    s32 width = request & 0xFF;
    s32 available = 8 - remainder;
    s32 take = available & 0xFF;
    s32 skip;
    s32 difference;
    s32 mask;
    s32 piece;
    u32 remaining;
    u32 result;

    if (available < width) {
        skip = 0;
    } else {
        take = width;
        skip = (8 - (width + remainder)) & 0xFF;
    }
    *cursor = (s32)((u32)*cursor + (u32)take);
    mask = 0xFF >> ((8U - (u32)take) & 31U);
    mask = (s32)(((u32)mask << ((u32)skip & 31U)) & 0xFFU);
    difference = width - take;
    remaining = (u32)difference & 0xFFU;
    piece = (s32)(*byte & mask) >> ((u32)skip & 31U);
    result = (u32)piece << ((u32)difference & 31U);

    if (remaining != 0) {
        do {
            ++byte;
            if (remaining >= 9U) {
                skip = 0;
                take = 8;
            } else {
                take = (s32)remaining;
                skip = (8U - remaining) & 0xFFU;
            }
            difference = (s32)remaining - take;
            *cursor = (s32)((u32)*cursor + (u32)take);
            mask = 0xFF >> ((8U - (u32)take) & 31U);
            mask = (s32)(((u32)mask << ((u32)skip & 31U)) & 0xFFU);
            remaining = (u32)difference & 0xFFU;
            piece = (s32)(*byte & mask) >> ((u32)skip & 31U);
            result |= (u32)piece << ((u32)difference & 31U);
        } while (remaining != 0);
    }
    return (s32)result;
}
