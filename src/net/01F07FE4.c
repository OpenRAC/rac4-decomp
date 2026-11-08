/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

void func_0011EAD0(void *);
void func_01F08038(void *);
extern s32 D_0016E660[];
extern s32 D_001B7FE0[];
void func_01F08418();

void *func_01F07FE4(void) {
    if (D_0016E660[0] == 0) {
        func_01F08038(D_001B7FE0);
        D_0016E660[0] = 1;
        func_0011EAD0(func_01F08418);
    }
    return D_001B7FE0;
}
