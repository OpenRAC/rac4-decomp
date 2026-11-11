/* cflags: -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x84];
    s32 f84;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E430[];
extern s32 D_0019C400[];

s32 func_01EEE13C(void) {
    if (D_0016E430[0] == NULL) {
        func_01F0C090(D_0019C400, 0x6D);
    }
    if (D_0016E430[0]->f84 == 0) {
        func_01F0C090(D_0019C400, 0x6E);
    }
    return D_0016E430[0]->f84;
}
