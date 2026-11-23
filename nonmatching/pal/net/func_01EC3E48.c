/* Not matching yet: PAL WIP; main net.text 0x01EC3E48, 124B. Not part of the build. */
/*
 * The supported index-forwarding/pointer repair expands old116B to true124B size but
 * leaves22nativeword differences (76unmaskedbytes) at all49placements. Enterbranch-likely with
 * restore/annulment, pointerallocationa0, statuscarrier and restorejoin remain different from
 * nativeordinarybranch/t7/t6 flow. This direction has no further establishednewnative dataflow
 * distinction; stop without type/ABI/return/helper/branch/CFG
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: e3d1fbcb7be2222c03ae93fa9ae3d98efabb1a8f15c759e1d3ecc6338b1ce894
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EC3E48 nonmatching/pal/net/func_01EC3E48.c --diff
 */
#include "common.h"

s32 func_01EC3460(void);
s32 func_01EC3498(void);
s32 func_01EC5280(s32 index);

/* Forward the record index and copy its words while entered. */
s32 func_01EC3E48(s32 arg0, void *arg1)
{
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_t7;

    temp_v0 = func_01EC3460();
    var_t7 = temp_v0;
    if (temp_v0 == 0) {
        var_s0 = 2;
        temp_v0_2 = func_01EC5280(arg0);
        if (temp_v0_2 != 0) {
            u8 *object = (u8 *)temp_v0_2;
            var_s0 = 0xCB2D;
            if (*(s32 *)(object + 8) == 8) {
                var_s0 = 0;
                *(s32 *)((u8 *)arg1 + 0) = *(s32 *)(object + 0x80);
                *(s32 *)((u8 *)arg1 + 4) = *(s32 *)(object + 0x84);
            }
        }
        func_01EC3498();
        var_t7 = var_s0;
    }
    return var_t7;
}
