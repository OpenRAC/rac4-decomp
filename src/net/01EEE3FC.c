/* cflags: -Os -G0 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x9C];
    s32 f9C;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E430;
extern s32 D_0019C400[];

s32 func_01EEE3FC(void) {
    if (D_0016E430 == NULL) {
        func_01F0C090(D_0019C400, 0xAB);
    }
    if (D_0016E430->f9C == 0) {
        func_01F0C090(D_0019C400, 0xAC);
    }
    return D_0016E430->f9C;
}
