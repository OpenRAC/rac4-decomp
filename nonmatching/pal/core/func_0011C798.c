/* Not matching yet: PAL WIP; main core.text 0x0011C798, 168B. Not part of the build. */
/*
 * Best ordinary graphs have full168B/control/delay/read/store structure but fixed
 * logical-role/plus-constant register choices: statusa3/accessv1 versus native statust1/accessa3,
 * extra t0 matches; plusconstant a0 versus nativev1. Other natural graph families emit152/164/176B
 * or altered joins. No useful distinct ordinary hypothesis remains currently established; stop
 * blind equivalent permutations rather than force regist
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a8888fd1a04ede1ad11b81679990b0f14a25f01cbc18a1a907851164e0412cb8
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0011C798 nonmatching/pal/core/func_0011C798.c --diff
 */
#include "common.h"

s32 func_0011C798(s32 *error, void *input, s32 *flags)
{
    s32 status;
    s32 access;
    s32 extra;
    s8 *bytes = input;

    switch (bytes[0]) {
    case 0x72:
        status = 4;
        access = 0;
        extra = 0;
        break;
    case 0x77:
        status = 8;
        access = 1;
        extra = 0x600;
        break;
    case 0x61:
        status = 0x108;
        access = 1;
        extra = 0x208;
        break;
    default:
        *error = 0x16;
        return 0;
    }

    if (bytes[1] == 0x2B) {
        status = 0x10;
        access = 2;
    } else if (bytes[2] == 0x2B) {
        status = 0x10;
        access = 2;
    }
    *flags = access | extra;
    return status;
}
