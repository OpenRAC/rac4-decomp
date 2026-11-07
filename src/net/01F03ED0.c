/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
struct Type2 {
    char _p0[0xB4];
    s32 fB4;
    s32 fB8;
};
struct Type1 {
    char _p0[0x5B10];
    s32 f5B10;
};

void func_01EE68FC(void *, s32, s32);
void func_01F0C090(void *, s32);
extern s32 D_0019E018[];

void func_01F03ED0(Type2 *arg0, Type1 *arg1) {
    if (arg1 == NULL) {
        func_01F0C090(D_0019E018, 0x40);
    }
    if ((arg1->f5B10 == 0) && (arg0->fB8 == 0)) {
        func_01EE68FC(arg1, arg0->fB4, 0);
        arg0->fB8 = 1;
    }
}
