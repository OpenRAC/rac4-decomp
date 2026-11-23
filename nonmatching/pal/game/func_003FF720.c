/* Not matching yet: PAL WIP; main .text 0x003FF720, 104B. Not part of the build. */
/*
 * Symbolic descriptor and allocated-bytepointer repair emits104B but retains twelve nativeword
 * differences at all3placements. After resolving newandold ordinarycalls toMain and
 * newdescriptorpair to3CCEC0, exactlytwo words differ from retainedbest: old LUI3C/ORI CEC0 versus
 * newLUI3D/ADDIU CEC0 at+60/+68. Every otherbyte is unchanged;
 * output/null/call-delay/result-register residual is fixed for this source/dataflow disti
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6846d9df6298a6c2f1866d9a1657eed523bb5686ce355f46ebf804dd982e8e66
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_003FF720 nonmatching/pal/game/func_003FF720.c --diff
 */
#include "common.h"

extern u8 D_003CCEC0[];
s32 func_004033B0(s32 value);
s32 func_003FE6C0(u8 *object);
void func_003FD508(u8 *object);

/* Allocate and initialize the object before publishing its identity fields. */
s32 func_003FF720(s32 *output)
{
    u8 *object;
    s32 result;

    object = (u8 *)func_004033B0(0x30);
    result = 0x206;
    *output = (s32)object;
    if (object != 0) {
        func_003FE6C0(object);
        func_003FD508(object + 0x14);
        *(u8 **)(object + 0x2C) = object;
        *(u8 **)(object + 0x28) = D_003CCEC0;
        result = 0;
    }
    return result;
}
