#include "common.h"

extern s32 func_001593C8(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern u8 D_0021DD84;
extern s32 D_21DAA0;
extern s32 D_21DAA4;

/* Clears two globals, writes 0xDEADBEEF through the pointer at arg0[0], clears the header of the block at arg1, calls func_001593C8 with the words of arg0 and returns whether it returned nonzero. */
s32 func_00163980(s32 *arg0, u8 *arg1) {
    u8 flag;

    D_21DAA0 = 0;
    D_21DAA4 = 0;
    *(u32 *)arg0[0] = 0xDEADBEEF;
    arg1[4] = 0;
    flag = D_0021DD84;
    arg1[6] = 0;
    arg1[5] = flag;
    arg1[7] = 0;
    *(s32 *)arg1 = 0;
    return func_001593C8(arg0[1], arg0[2], arg0[0], arg1 + 4) != 0;
}
