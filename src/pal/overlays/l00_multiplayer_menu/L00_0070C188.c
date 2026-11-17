/* cflags: -O2 -G0 -Wuninitialized */
#include "pal/profile_001721E0.h"


s32 func_00154F18(s32 handle, s16 *flags);

s32 func_L00_0070C188(void) {
    s16 flags;

    if (D_001721E0.region20.words.f28 != -1) {
        flags = 0;
        if (func_00154F18(D_001721E0.region20.words.f28, &flags) == 0) {
            return ((u16)flags >> 1) & 1;
        }
    }
    return 0;
}
