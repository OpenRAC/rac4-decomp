/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EE50D4(void **);
s32 func_01EE9E54(void **, s32);
s32 func_01F070D0();
extern s32 D_0016FC48[];

void func_01EE51CC(void **arg0, s32 arg1) {
    *arg0 = D_0016FC48;
    func_01F070D0();
    func_01EE9E54(arg0, 0);
    if (arg1 & 1) {
        func_01EE50D4(arg0);
    }
}
