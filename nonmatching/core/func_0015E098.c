/* Not matching yet: BYTES 2/92 (tools/try_func.py func_0015E098 build/try/func_0015E098/p6.c --diff). Not part of the build.
 * The forwarded four-argument indirect call preserves a0-a3 and produces retail's stack and global-base allocation.
 * Only the commutative addu source-register order at +0x10 remains different. */
#include "common.h"

extern u8 D_00172160[];
extern s32 (*D_00212150[])(s32, s32, s32, s32);
#define D_00212150 (D_00212150[0])

s32 func_0015E098(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 index = D_00172160[arg2 + 0x6C9];
    s32 result;

    if (index < 10) {
        *(s32 *)(D_00172160 + (index << 2) + 0x6A0) = *(s32 *)(D_00172160 + 0x218);
    }
    result = -1;
    if (D_00212150 != NULL) {
        result = D_00212150(arg0, arg1, arg2, arg3);
    }
    return result;
}
