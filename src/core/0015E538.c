/* cflags: -G0 */
#include "common.h"

extern s32 (*D_00212180)();

typedef struct {
    u8 pad0[0x218];
    s32 f218;
    u8 pad2[0x6A0 - 0x21C];
    s32 f6A0[10];
    u8 pad3[1];
    u8 f6C9[16];
} Type1;

extern Type1 D_00172160;

/* Copy the word at 0x218 into the table slot selected by the byte at 0x6C9 + the
   third argument, then let the installed hook adjust the result. */
s32 func_0015E538(s32 a0, s32 a1, s32 idx, s32 a3)
{
    u8 c = D_00172160.f6C9[idx];
    s32 r;

    if (c < 10) {
        D_00172160.f6A0[c] = D_00172160.f218;
    }
    r = -1;
    if (D_00212180 != 0) {
        r = D_00212180(a0, a1, idx, a3);
    }
    return r;
}
