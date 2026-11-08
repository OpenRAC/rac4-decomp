/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_0011EAA0(void *, s32, void *);
extern s32 D_00199F28[];
extern s32 D_0019A270[];
extern s32 D_0019A280[];

s32 func_01EE0340(s32 *arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        func_0011EAA0(D_00199F28, 0x405, D_0019A270);
    }
    if (*arg0 != 8) {
        func_0011EAA0(D_00199F28, 0x408, D_0019A280);
    }
    *arg0 = 9;
    return arg2;
}
