/* Load the global pointer to a callback slot, return zero if either pointer is null, otherwise call the callback. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 (**D_0021EBD4)();

s32 func_L01_00584068(void) {
    s32 (*temp_v0)();

    if ((D_0021EBD4 == NULL) || (temp_v0 = *D_0021EBD4, (temp_v0 == NULL))) {
        return 0;
    }
    return temp_v0();
}
