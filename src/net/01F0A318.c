/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    void *f0;
    char _p4[0x204];
    s32 f208;
};

s32 func_01EEE13C();
s32 func_01EF0550(s32, s32);
s32 func_01F0A6A4(void *);
extern s32 D_0016FF28[];
extern s32 D_00170F58[];

void func_01F0A318(Type1 *arg0, s32 arg1) {
    arg0->f0 = D_00170F58;
    if (arg0->f208 != 0) {
        func_01EF0550(func_01EEE13C(), arg0->f208);
    }
    arg0->f0 = D_0016FF28;
    if (arg1 & 1) {
        func_01F0A6A4(arg0);
    }
}
