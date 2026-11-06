#include "common.h"

typedef struct { s32 v; s32 f4; s32 f8; } Ent;
extern Ent D_00270040[];
s32 D_0021F2F4 = 0;

/* Word 0 of entry D_0021F2F4 - 1 of the 12-byte table D_00270040, or -2 when D_0021F2F4 is 0. */
s32 func_0047F870(void) {
    if (D_0021F2F4 != 0) {
        return D_00270040[D_0021F2F4 - 1].v;
    }
    return -2;
}
