/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    void *f0;
    char _p4[0x4];
    s32 f8;
    char _pC[0xC];
    s32 f18;
    s32 f1C;
};

s32 func_01F0C090(void *, s32);
s32 func_01F0C4EC(void *);
extern s32 D_00171170[];
extern s32 D_0019E918[];

void func_01F0C410(Type1 *arg0, s32 arg1, s32 arg2) {
    arg0->f1C = arg2;
    arg0->f0 = D_00171170;
    if (arg1 == 0) {
        func_01F0C090(D_0019E918, 0x61);
    }
    arg0->f18 = arg1;
    arg0->f8 = 0;
    func_01F0C4EC(arg0);
}
