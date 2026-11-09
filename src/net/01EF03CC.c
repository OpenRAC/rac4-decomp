/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x1041C];
    void *f1041C;
};

s32 func_0015DB88(void *);
s32 func_01EF0604();
extern s32 D_0016FE68[];

void func_01EF03CC(Type1 *arg0, s32 arg1) {
    arg0->f1041C = D_0016FE68;
    func_01EF0604();
    if (arg1 & 1) {
        func_0015DB88(arg0);
    }
}
