/* Not matching yet: PAL WIP; level_00 .text 0x005380B0, 312B. Not part of the build. */
/*
 * Resolved count captures, signedmax, capacity comparison, resize call and successful resize guard
 * +84..+B3 are identical. Later failure-branch displacement differs because return join differs;
 * no wider block equality claimed.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 2e5261ab211fa30b71d02a48a9a19ca7c898cf9bb5e9ff9231fc59ec114dd18b
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_005380B0 nonmatching/pal/l00_multiplayer_menu/func_L00_005380B0.c --diff
 */
#include "common.h"

extern s32 func_L00_00537D88(void *, void *, void *);
extern s32 func_L00_00537EF8(void *, void *, void *);
extern int func_L00_005387C8(int, int);
extern s32 func_L00_00538C70(void *, void *);

s32 func_L00_005380B0(void *out, void *left, void *right)
{
    s32 different = 0;
    s32 sign = 0;
    s32 rightCount, leftCount, capacity, needed;
    void *swap;

    if (*(s32 *)((u8 *)left + 12) != 0) {
        if (*(s32 *)((u8 *)right + 12) != 0) {
            swap = left;
            left = right;
            right = swap;
        } else {
            different = 1;
            sign = 1;
        }
    } else {
        different = *(s32 *)((u8 *)right + 12) != 0;
    }

    if (different) {
        if (func_L00_00537D88(out, left, right) == 0)
            return 0;
    } else {
        rightCount = *(s32 *)((u8 *)right + 4);
        leftCount = *(s32 *)((u8 *)left + 4);
        capacity = *(s32 *)((u8 *)out + 8);
        needed = rightCount < leftCount ? leftCount : rightCount;
        if (capacity < needed) {
            if (func_L00_005387C8((s32)out, needed) == 0)
                return 0;
        } else if (out == NULL) {
            return 0;
        }
        if (func_L00_00538C70(left, right) < 0) {
            if (func_L00_00537EF8(out, right, left) == 0)
                return 0;
            sign = 1;
        } else {
            if (func_L00_00537EF8(out, left, right) == 0)
                return 0;
            sign = 0;
        }
    }
    *(s32 *)((u8 *)out + 12) = sign;
    return 1;
}
