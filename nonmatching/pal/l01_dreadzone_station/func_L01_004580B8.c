/* Not matching yet: PAL WIP; level_01 .text 0x004580B8, 104B. Not part of the build. */
/*
 * Private original-object predicate/getter forwarding has inherited no-argument MATCH source ABI
 * debt. Actual result/frame/guard/layout remain nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b1c5f9196c7e4cb23da738916f02de549d84253598b6f42aa230ac36bc2fdef1
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_004580B8 nonmatching/pal/l01_dreadzone_station/func_L01_004580B8.c --diff
 */
#include "common.h"

s32 func_00483340(void *object);

s32 func_L01_004580B8(void *object)
{
    s32 predicate;
    s32 status;
    u8 state;

    predicate = func_00483340(object);
    status = 0;
    if (predicate == 1) {
        status = 1;
    } else {
        state = *(u8 *)((u8 *)object + 0x20);
        if (state == 4) {
            status = 1;
        } else if (object == NULL || state == 0xFE || state == 0xFD) {
            status = 1;
        }
    }
    return status;
}
