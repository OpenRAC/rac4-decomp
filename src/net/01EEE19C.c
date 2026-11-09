/* cflags: -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x98];
    s32 f98;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E430[];
extern s32 D_0019C400[];

s32 func_01EEE19C(void) {
    if (D_0016E430[0] == NULL) {
        func_01F0C090(D_0019C400, 0x74);
    }
    if (D_0016E430[0]->f98 == 0) {
        func_01F0C090(D_0019C400, 0x75);
    }
    return D_0016E430[0]->f98;
}
