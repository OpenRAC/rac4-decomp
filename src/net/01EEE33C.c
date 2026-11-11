/* cflags: -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x94];
    s32 f94;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E430[];
extern s32 D_0019C400[];

s32 func_01EEE33C(void) {
    if (D_0016E430[0] == NULL) {
        func_01F0C090(D_0019C400, 0x9D);
    }
    if (D_0016E430[0]->f94 == 0) {
        func_01F0C090(D_0019C400, 0x9E);
    }
    return D_0016E430[0]->f94;
}
