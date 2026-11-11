/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses -fno-optimize-sibling-calls -Wa,-G0 */
#include "common.h"

typedef struct Type1 {
    u8 pad0[0x8C];
    s32 f8C;
} Type1;

void func_01F0C090(s32 *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

s32 func_01EEE45C(void)
{
    Type1 *p;
    if (D_0016E430 == NULL) {
        func_01F0C090(D_0019C400, 0xB2);
    }
    p = D_0016E430;
    if (p->f8C == 0) {
        func_01F0C090(D_0019C400, 0xB3);
    }
    p = D_0016E430;
    return p->f8C;
}
