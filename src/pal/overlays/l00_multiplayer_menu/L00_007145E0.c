/* cflags: -G0 */
/* cflags: -G0 */
/* C adapted from rac3-decomp func_003AACC8 (NTSC-U func_003AAB70, commit 403f30a9) */
#include "common.h"

extern s32 func_0015DB98();
extern u8 D_004B7B38[];
void func_L00_007145E0(u8 *p, s32 f) {
    *(void **)(p + 88) = D_004B7B38;
    if (f & 1) func_0015DB98(p);
}
