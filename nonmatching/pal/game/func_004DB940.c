/* Not matching yet: PAL WIP; main .text 0x004DB940, 84B. Not part of the build. */
/*
 * No primary exact. Closest shared-return84B form has native initial ID branch/return
 * instructions, but folds provider+36 into address/negativeoffset bases rather than native
 * highpart copy and fullbase rematerializations. Branch joins/likelydelay differ and explicit ANDI
 * count1F survives before SRAV; native directly consumes a0 low5. No
 * cast/width/mask-removal/flags/register workaround was attempted. Address/result sco
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 33828af51c6517868809acf6119b3097b14940ee8463bcd9f1272be20e16059e
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004DB940 nonmatching/pal/game/func_004DB940.c --diff
 */
#include "common.h"
extern s32 D_00171BC0[];

s32 func_004DB940(s32 id) {
    if (id == 0 || id == 5) {
available:
        return 1;
    }
    if (*(s16 *)((u8 *)D_00171BC0 + 0x36) >= id) goto available;
    if (id < 5 && *((u8 *)D_00171BC0 + 0x26) != 0) goto available;
    return (*(s32 *)((u8 *)D_00171BC0 + 0x18) >> ((u32)id & 31)) & 1;
}
