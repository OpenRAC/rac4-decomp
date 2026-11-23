/* Not matching yet: PAL WIP; main net.text 0x01ED80F8, 124B. Not part of the build. */
/*
 * Invalid scratch-store GPREL16: physical0x1BC9B8-GP0x2259FF=-0x69047, outside signed16. Intended
 * threshold capture precedes stores, but actual second store cannot bind correctly. Inherited
 * fourth-helper-argument source ABI qualification remains.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 716d38c11c7a29a90b59dc760410ae15a99cb8302d30b7222c51d63eef347f93
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01ED80F8 nonmatching/pal/net/func_01ED80F8.c --diff
 */
#include "common.h"

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_PAL_MAIN_001BCBB0;
extern s32 D_PAL_MAIN_001BC9B8;

s32 func_01ED5DD0(s32, s32, s32, s32);

s32 func_01ED80F8(void *record, void *callbackAddress, s32 word)
{
    u32 threshold;

    *((u8 *)record + 0x14) = 0;
    if (D_00169CD0 != 1) {
        return -15;
    }
    if (D_00169CD4 == 0) {
        return -16;
    }

    threshold = *(u32 *)((u8 *)record + 0x1C);
    D_PAL_MAIN_001BCBB0 = (s32)callbackAddress;
    D_PAL_MAIN_001BC9B8 = word;
    if (threshold >= 0x64U) {
        *(u32 *)((u8 *)record + 0x1C) = 0;
    }

    return func_01ED5DD0(1, 0xF1, 0x24, (s32)record) == 0 ? 0 : -5;
}
