/* Not matching yet: PAL WIP; main core.text 0x0014DDC0, 188B. Not part of the build. */
/*
 * Native+00..+14: SLL;CONST255;SRA;LBkind;SLTI mode<255;MOVN(selected=mode). Actual+00..+18:
 * SLL;CONST254;SRA;CONST255;SLT254<mode;LBkind;MOVZ(selected=mode). Equivalent signed partitions,
 * one extra instruction; h02 statement graph emits same text.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b53a3a492b1b1ba36504458d11aa85c60286f2ba8a311c4d2b3725fdeed1e351
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0014DDC0 nonmatching/pal/core/func_0014DDC0.c --diff
 */
#include "common.h"

typedef struct Detector Detector;

s32 func_0014DDC0(s16 mode, u16 period, Detector *state, f32 threshold)
{
    u8 *p = (u8 *)state;
    s32 selected = mode < 255 ? mode : 255;
    s8 kind = *(s8 *)(p + 0x14);

    if (kind == 1) {
        s8 active = *(s8 *)(p + 0x15);
        *(u16 *)(p + 0x10) = 0;
        if (active == 0 && (f32)selected <= threshold) {
            *(s8 *)(p + 0x15) = kind;
        }
    } else {
        f32 product = (f32)period * *(f32 *)(p + 8);
        u32 next = (u32)*(u16 *)(p + 0x10) + 1u;
        s32 scaled_next = (s32)(next << 16);
        s32 converted;

        *(u16 *)(p + 0x10) = (u16)next;
        converted = (s32)(product + 0.5f);
        if ((s32)((u32)converted << 16) < scaled_next) {
            *(s8 *)(p + 0x15) = 0;
            if ((s16)next >= 0x7FBD) {
                *(u16 *)(p + 0x10) = 0x7FBC;
            }
        }
    }
    return *(s8 *)(p + 0x15);
}
