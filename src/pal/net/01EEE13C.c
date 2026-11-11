/* cflags: -Os -G8 -mno-split-addresses -mips3 -mcpu=r4000 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[132];
    s32 f98;
};

s32 func_01F0C090(void *, s32);
extern Type1 *D_0016E4B0[];
extern s32 D_0019C480[];

s32 func_01EEE13C(void) {
    if (D_0016E4B0[0] == NULL) {
        func_01F0C090(D_0019C480, 109);
    }
    if (D_0016E4B0[0]->f98 == 0) {
        func_01F0C090(D_0019C480, 110);
    }
    return D_0016E4B0[0]->f98;
}
