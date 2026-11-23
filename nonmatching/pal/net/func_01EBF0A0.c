/* Not matching yet: PAL WIP; main net.text 0x01EBF0A0, 96B. Not part of the build. */
/*
 * Compiled104B versus complete native96B; new compiled text is not an old104B object duplicate.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 361690a027684069fdc6a47d9630eacf61828ba735a2465243653cfe4da69079
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EBF0A0 nonmatching/pal/net/func_01EBF0A0.c --diff
 */
#include "common.h"

extern s32 func_01EC0DB8(void *owner, void *state);

/* Forward the owner and state after the guarded transition to state nine. */
s32 func_01EBF0A0(void *owner, s32 *state)
{
    s32 previous;
    s32 status;

    status = 2;
    if (owner != NULL) {
        status = 0xD2F3;
        if (state != NULL) {
            previous = *state;
            status = 0xD2F4;
            if (previous == 8) {
                *state = 9;
                status = func_01EC0DB8(owner, state);
                if (status != 0) {
                    *state = 7;
                    status = 0xD2F7;
                }
            }
        }
    }
    return status;
}
