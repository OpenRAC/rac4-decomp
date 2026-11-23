/* Not matching yet: PAL WIP; main .text 0x00527668, native 168B. Not part of the build. */
/*
 * Actual default-PAL body is 176B. Shared early-one/nonzero-first/result control
 * is recovered, but an EXTRA deep-status LW at +0x6C executes in the ordinary
 * threshold-rejection branch delay, where native skips that memory read.
 * Actual GPREL16 for D_PAL_MAIN_00354634__gp cannot bind: S=0x00354634,
 * A=0, GP=0x002259FF, S+A-GP=+0x12EC35, outside signed16. No truncation.
 * Source capture is not emitted-effect proof. No valid bound/near/match,
 * source-ABI, header-view or data-owner approval is implied by this WIP.
 * Body retained without C token edits; see reviewed C75 evidence.
 * Reproduce only when separately authorized: python3 tools/check_func.py
 *   --version pal func_00527668 nonmatching/pal/game/func_00527668.c --diff
 */
#include "common.h"
#include "pal/profile_001721E0.h"

extern s32 D_0021DE3C;
extern s32 D_PAL_MAIN_001729AC[];
extern s32 D_PAL_MAIN_001729D4;
extern s32 D_PAL_MAIN_00354634;

/* Select the object status through the ordered state and lookup regions. */
s32 func_00527668(void *object)
{
    s32 selected = 0;

    if (D_001721E0.f258 == 0)
        goto inspect_mode;
return_one:
    return 1;

inspect_mode:
    if (D_0021DE3C == 0xF)
        goto return_one;

    if (object != NULL) {
        if (*(u8 *)((u8 *)object + 0x266D) != 0) {
            selected = 1;
            if (D_001721E0.f1C >= 2) {
                u32 current = D_001721E0.region20.words.f218;
                s32 limit = D_PAL_MAIN_001729D4;
                if (limit < (s32)(current - 0x7D0U)) {
                    if (D_PAL_MAIN_00354634 >= 1)
                        selected = 0;
                }
            }
        } else {
            u32 *descriptor = *(u32 **)((u8 *)object + 0x2F28);
            u32 current = D_001721E0.region20.words.f218;
            u32 offset = *descriptor;
            u8 entry = *(u8 *)((u32)&D_001721E0 + offset + 0x6C9U);
            s32 previous = D_PAL_MAIN_001729AC[entry];
            selected = (s32)(current - (u32)previous) < 0x5DD;
        }
    }
    return selected;
}
