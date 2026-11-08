/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_0011A518(void *, s32, s32);
s32 func_01EAB270(void *);
extern s32 D_00168BAC[];
extern s32 D_001B2420[];
extern s32 D_001B25B8[];

void func_01EABEE0(void) {
    if (D_00168BAC[0] == 0) {
        func_0011A518(D_001B2420, 0, 0x198);
        D_00168BAC[0] = 1;
    }
    func_01EAB270(D_001B25B8);
}
