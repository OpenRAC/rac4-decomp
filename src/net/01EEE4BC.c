/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xA0];
    s32 fA0;
};

void func_01F0C090(void *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

s32 func_01EEE4BC(void) {
    Type1 *p;
    if (D_0016E430 == NULL) {
        func_01F0C090(D_0019C400, 0xB9);
    }
    p = D_0016E430;
    if (p->fA0 == 0) {
        func_01F0C090(D_0019C400, 0xBA);
    }
    p = D_0016E430;
    return p->fA0;
}
