/* Not matching yet: SIZE ours 64 / retail 40 (tools/try_func.py func_L00_0052ADF0 --diff). Not part of the build. */
/* Wall, not a C problem: retail's func_L00_0052ADF0 and func_L00_0052AE18 are one
   function that tools/split_overlays.py cut in two at the mid-function `jr $ra`
   (0x0052AE14). The tail `bnel $v0, $zero, func_L00_0052AE18` at 0x0052AE08 jumps
   into a continuation that reads $v1 without ever setting it (`addiu $a2, $v1, -0x1`
   in asm/overlays/L00/nonmatchings/text_005156F8/func_L00_0052AE18.s) and $v1 is
   exactly the count func_L00_0052ADF0 loaded from arg0->f0; the only `jal` in that
   section targets 0x0052ADF0, not 0x0052AE18. So neither half can match with plain C:
   the boundary in config/splat.yaml (and config/overlay_functions.tsv) has to merge
   them first, then the merged body can be decompiled under one name. */
#include "common.h"

extern s32 func_L00_0052AE18(s32, s32);

// True when entry `index` of the table is marked.
s32 func_L00_0052ADF0(u8 *p, s32 index) {
    if (*(s32 *)p == 0) {
        return 0;
    }
    if (index < 0) {
        return 0;
    }
    if (index < *(s32 *)p) {
        return func_L00_0052AE18(*(s32 *)(p + 4), index);
    }
    return 0;
}

