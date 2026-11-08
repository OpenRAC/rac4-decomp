/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0019E050[];

s32 func_01F0410C(Type1 *arg0) {
    if (arg0->f4 == 0) {
        func_01F0C090(D_0019E050, 0x24);
    }
    return arg0->f4;
}
