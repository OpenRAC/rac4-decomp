/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};

s32 func_01F0C090(void *, s32);
extern s32 D_0016E65C;
extern s32 D_0019E3C8;

s32 func_01F07BCC(Type1 *arg0, s32 *arg1) {
    if (arg1 == NULL) {
        func_01F0C090(&D_0019E3C8, 0xB1);
    }
    if (arg0->f4 != 0) {
        arg0->f4 = 0;
        *arg1 = D_0016E65C;
        return 1;
    }
    return 0;
}
