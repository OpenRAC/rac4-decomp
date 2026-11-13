/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA9550(s32 *, u64);
extern void func_0011D5D8(void *);
extern u8 D_00195DF0[];
s32 func_01EA0668(u32 arg0) {
    s32 x = 0;
    if (func_01EA9550(&x, arg0) != 0) {
        func_0011D5D8(D_00195DF0);
    }
    return x;
}
