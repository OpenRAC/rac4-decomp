/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x250];
    s32 f250;
    s32 f254;
    s32 f258;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E200[];

s32 func_01F06308(Type1 *arg0) {
    if (arg0->f250 >= 0x65) {
        func_01F0C090(D_0019E200, 0x2AA);
    }
    if (arg0->f258 > arg0->f250) {
        func_01F0C090(D_0019E200, 0x2AB);
    }
    if (arg0->f254 > arg0->f250) {
        func_01F0C090(D_0019E200, 0x2AC);
    }
    return arg0->f254;
}
