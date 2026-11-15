/* Not matching yet: 13/25 (52.00%) relocation-masked positional words; 100/100 candidate/target bytes. Existing caller prototype conflicts; the returned pointer needs a readable +12 word. Reproduce: python tools/check_func.py --version pal func_01EC8F00 nonmatching/pal/net/func_01EC8F00.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"

/* 13/25 target words match (52.00%) under relocation-masked positional
 * comparison; 100/100 bytes. Scheduling and register placement differ.
 * The selected callee matches this declaration; an existing caller has a
 * conflicting prototype. The returned address requires a readable +12 word.
 * Verify with tools/diff_func.py --version pal func_01EC8F00. */
extern s32 func_01EA47E8(s32 *, u32);
s32 func_01EC8F00(s32 *arg0, s32 *arg1, u32 arg2) {
    s32 var_2; s32 temp_2;
    var_2=0x17;
    if (arg0 == NULL) goto block_6;
    *arg0=0;
    if (arg2 >= 0x100U) goto block_5;
    temp_2=func_01EA47E8(arg1,arg2);
    var_2=0;
    if (temp_2==0) goto block_6;
    *arg0=*(s32 *)((u8 *)temp_2+0xC);
    return 0;
block_5: var_2=8;
block_6: return var_2;
}