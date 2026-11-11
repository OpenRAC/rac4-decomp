/* Not matching yet: SIZE ours 52 / retail 56; sq/lq $ra where retail has sd/ld, sltu into $v1 not $v0 (tools/try_func.py func_0049A3A8 --diff). Not part of the build. */
#include "common.h"

extern s32 func_00497458(s32 playerIndex, u32 previousState);
extern s32 D_0021DDB4;

s32 func_0049A3A8(s32 playerIndex)
{
    u8 r = 0;

    if (D_0021DDB4 == 0) {
        r = func_00497458(playerIndex, 0) != 0;
    }
    return r;
}
