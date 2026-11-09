/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x88];
    s32 f88;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

s32 func_01EEE39C(void) {
    Type1 *p;
    p = D_0016E430;
    if (p == NULL) {
        func_01F0C090(D_0019C400, 0xA4);
    }
    p = D_0016E430;
    if (p->f88 == 0) {
        func_01F0C090(D_0019C400, 0xA5);
    }
    p = D_0016E430;
    return p->f88;
}
