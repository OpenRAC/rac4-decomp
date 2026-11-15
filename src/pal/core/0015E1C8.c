/* cflags: -G0 */
/* cflags: -G0 */
#include "common.h"

extern s32 (*D_002121DC)();

#include "pal/profile_001721E0.h"

/* Copy the word at 0x218 into the table slot selected by the byte at 0x6C9 + the
   third argument, then let the installed hook adjust the result. */
s32 func_0015E1C8(s32 a0, s32 a1, s32 idx, s32 a3)
{
    u8 c = D_001721E0.f6C9[idx];
    s32 r;

    if (c < 10) {
        D_001721E0.f6A0[c] = D_001721E0.region20.words.f218;
    }
    r = -1;
    if (D_002121DC != 0) {
        r = D_002121DC(a0, a1, idx, a3);
    }
    return r;
}
