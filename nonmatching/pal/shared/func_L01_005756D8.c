/* Not matching yet: PAL WIP; level_01 .text 0x005756D8, 36B. Not part of the build. */
/*
 * Stock compiler null-arm layout and scheduling of the three stores differ at six words despite
 * correct unsigned sentinel materialization. No additional native-supported source/dataflow
 * distinction is established for another trial.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6559c2d08619cb849c5a7e1333e24f312aa3bc72fbf36d98b1280d6b00f9700f
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_005756D8 nonmatching/pal/shared/func_L01_005756D8.c --diff
 */
#include "common.h"

/* Reset the supplied record, accepting null and always returning one. */
s32 func_L01_005756D8(void *arg0)
{
    if (arg0 != NULL) {
        *(s32 *)((s8 *)arg0 + 0) = 0;
        *(u16 *)((s8 *)arg0 + 0xC) = 0xFFFF;
        *(u16 *)((s8 *)arg0 + 6) = 0;
        return 1;
    }
    return 1;
}
