/* Not matching yet: PAL WIP; level_00 .text 0x006D5840, 188B. Not part of the build. */
/*
 * Actual object reverses object-clear store order in addition to fixed base/scheduling
 * differences; source order is not output certification.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 30537c46d4643c37079e964578c487cd114e5099c07a7971a90fe1264abff7aa
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_006D5840 nonmatching/pal/shared/func_L00_006D5840.c --diff
 */
#include "common.h"

extern s32 D_00171BC0[];
extern s16 D_004C4958[];

void func_L00_006D5840(void *arg0)
{
    u8 *state = (u8 *)D_00171BC0;
    u8 *object = (u8 *)arg0;
    s16 *cursor = D_004C4958;
    u32 sum = 0;
    u32 middle = 1400;
    u32 high = (u32)-4000;
    s32 index = 0;
    s32 previous;
    f32 snapshot;
    u32 remainder;

    if (*(s32 *)(state + 0x30) == 0 || *(s32 *)(state + 0x38) == 0) {
        *(f32 *)(state + 0x14) = (f32)*(s32 *)(state + 8);
    }
    *(s32 *)(object + 0x2FBC) = 0;
    *(u8 *)(object + 0x2FB8) = 0;

    do {
        if (index < 40) {
            sum += (u32)*cursor;
        } else if (index < 90) {
            sum += middle;
        } else {
            sum += high;
        }
        index += 1;
        if (*(s32 *)(state + 8) < (s32)sum) {
            break;
        }
        *(s32 *)(state + 0x38) = (s32)sum;
        high += 100;
        middle += 40;
        cursor += 2;
    } while (index < 999);

    previous = *(s32 *)(state + 0x38);
    snapshot = *(f32 *)(state + 0x14);
    remainder = sum - (u32)previous;
    *(s32 *)(state + 0x30) = (s32)snapshot;
    *(s32 *)(state + 0x38) = (s32)remainder;
}
