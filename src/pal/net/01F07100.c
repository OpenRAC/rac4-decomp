/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

void func_0011EAD0(void *);
void func_01F07154(void *);
extern s32 D_0016E6D4[];
extern s32 D_001B8020[];
void func_01F075D0();

void *func_01F07100(void) {
    if (D_0016E6D4[0] == 0) {
        func_01F07154(D_001B8020);
        D_0016E6D4[0] = 1;
        func_0011EAD0(func_01F075D0);
    }
    return D_001B8020;
}
