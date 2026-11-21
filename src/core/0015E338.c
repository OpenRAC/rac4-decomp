/* cflags: -G0 */
#include "common.h"

extern s32 (*D_21216C)();

typedef struct {
    u8 pad0[0x218];
    s32 f218;
    u8 pad2[0x6A0 - 0x21C];
    s32 f6A0[10];
    u8 pad3[1];
    u8 f6C9[0x7CC - 0x6C9];
    s32 f7CC[10];
    s32 f7F4;
} Type1;

extern Type1 D_00172160;

/* Copy the word at 0x218 into the two tables at the slot chosen by the byte at 0x6C9 + idx, then call the hook. */
s32 func_0015E338(s32 a0, s32 a1, s32 idx, s32 a3)
{
    u8 c = D_00172160.f6C9[idx];
    s32 r;

    if (c < 10) {
        D_00172160.f6A0[c] = D_00172160.f218;
        D_00172160.f7CC[c] = D_00172160.f218;
        D_00172160.f7F4 = D_00172160.f218;
    }
    r = -1;
    if (D_21216C != 0) {
        r = D_21216C(a0, a1, idx, a3);
    }
    return r;
}
