/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; char _p8[0xF8]; } Ent;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; Ent e[64]; } Blk;
extern s32 func_01EA9550(Blk **, s32);
Blk *func_01ED3A50(void) {
    Blk *b = 0;
    func_01EA9550(&b, sizeof(Blk));
    if (b != 0) {
        u32 i;
        b->f4 = 0xFFFFFF;
        b->f0 = 1;
        b->f8 = 0;
        b->fC = 0;
        for (i = 0; i < 64; i++) {
            b->e[i].f0 = 0;
            b->e[i].f4 = 0;
        }
    }
    return b;
}
