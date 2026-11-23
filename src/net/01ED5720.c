/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 D_00169D38;
extern u8 D_1B76C0[];
extern u8 D_1B7788[];

void func_01ED5720(u8 *a0) {
    if (D_00169D38 == 0x12)
        goto L12;
    if (D_00169D38 == 0x2D)
        func_0011A370(a0, D_1B76C0, 0xC4);
    goto out;
L12:
    func_0011A370(a0, D_1B7788, 0xEC);
out:
    return;
}
