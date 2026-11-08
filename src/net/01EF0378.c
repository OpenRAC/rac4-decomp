/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x7F0];
    s32 f7F0;
};

s32 func_01EF0550(s32, s32);
s32 func_01F0C090(void *, s32);
extern s32 D_0016E440[];
extern s32 D_0019C500[];

void func_01EF0378(Type1 *arg0) {
    if (D_0016E440[0] == 0) {
        func_01F0C090(D_0019C500, 0x122);
    }
    func_01EF0550(arg0->f7F0, D_0016E440[0]);
    D_0016E440[0] = 0;
}
