/* Not matching yet: PAL WIP; level_01 .text 0x004E6DB8, 80B. Not part of the build. */
/*
 * Private predicate(object) follows native consumed input; current source-interface debt remains
 * qualified. Actual FP/read/result layout is nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 2741f4790588285d1283d8232d492851aceb5cf02e232285f3beca3e9add8bb0
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004E6DB8 nonmatching/pal/l01_dreadzone_station/func_L01_004E6DB8.c --diff
 */
#include "common.h"

typedef struct {
    u8 pad[0x50];
    f32 value;
} LevelData;

typedef struct {
    u8 pad_00[0x20];
    u8 mode;
    u8 pad_21[0xAC - 0x21];
    LevelData *data;
} LevelObject;

extern s32 func_L01_004E4E50(LevelObject *object);

f32 func_L01_004E6DB8(void *object)
{
    u8 *payload;
    f32 denominator;
    f32 numerator;

    payload = *(u8 **)((u8 *)object + 0xAC);
    if (func_L01_004E4E50(object) != 0) {
        return 1.0f;
    }
    denominator = (f32)*(s32 *)(payload + 0x54);
    numerator = *(f32 *)(payload + 0x50);
    return 1.0f - numerator / denominator;
}
