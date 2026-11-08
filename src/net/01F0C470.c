/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01F0C4CC(void **);
s32 func_01F0C4EC();
extern s32 D_00171170[];

void func_01F0C470(void **arg0, s32 arg1) {
    *arg0 = D_00171170;
    func_01F0C4EC();
    if (arg1 & 1) {
        func_01F0C4CC(arg0);
    }
}
