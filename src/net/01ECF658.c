/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { char _p0[0xF8]; u32 fF8; s32 fFC; char _p100[0x10]; u32 f110; } Ctx;
extern Ctx *D_00167F38;
extern s32 D_00169B38;
extern char D_001B73D8[];
s32 func_01EA9550(char *, u64);
s32 func_01EA42D8(s32);
s32 func_01ECF658(void) {
    Ctx *c = D_00167F38;
    if (c->f110 >= c->fF8) {
        return 8;
    }
    D_00169B38 = 0;
    return func_01EA42D8(func_01EA9550(D_001B73D8, (u32)(c->fFC * 4)));
}
