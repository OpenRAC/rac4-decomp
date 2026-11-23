/* Not matching yet: PAL WIP; level_01 .text 0x004DAD90, 340B. Not part of the build. */
/*
 * Missing native redundantANDIFF, payload/type register roles; selected2/3 conversion still
 * forward joins before common math.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 69341d6e8245ce457a3cf7eb6a8d27c85af4b02be672c50d66d8b9a3098a16ce
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004DAD90 nonmatching/pal/shared/func_L01_004DAD90.c --diff
 */
#include "common.h"

f32 func_L01_004DAD90(void *object)
{
    f32 rawDenominator;
    s16 numerator;
    s32 typeWord;
    s32 selected;
    u8 type;
    void *payload;

    type = *(u8 *)((u8 *)object + 0x20);
    typeWord = type;
    payload = *(void **)((u8 *)object + 0xAC);
    if (typeWord == 5 || typeWord == 0 || typeWord == 6) {
        return 0.0f;
    }
    if (typeWord == 4) {
        return 1.0f;
    }
    if ((u32)(type - 2) < 2U) {
        selected = *(s32 *)((u8 *)payload + 0x124);
        if (selected == -1) {
            rawDenominator = (f32)*(s32 *)((u8 *)payload + 0x104);
        } else {
            rawDenominator = (f32)selected;
        }
        return (f32)*(s16 *)((u8 *)payload + 0x116) /
               (f32)(s32)(rawDenominator * 50.0f);
    }
    numerator = *(s16 *)((u8 *)payload + 0x114);
    if (typeWord != 1) {
        return 1.0f - ((f32)numerator /
               (f32)(s32)((f32)*(s32 *)((u8 *)payload + 0x104) * 50.0f));
    }
    return 1.0f - ((f32)numerator /
           (f32)(s32)((f32)*(s32 *)((u8 *)payload + 0x104) * 50.0f));
}
