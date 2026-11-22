/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00453608(s32, s32, s32);
extern void func_00453718(s32, void *, s32);
extern s32 D_002224FC;
extern s32 D_00222500;

void func_L00_005D3830(u8 *arg0, s32 *arg1) {
    s32 i;
    s32 n;

    n = *(s32 *)arg0;
    D_00222500 = n;
    D_002224FC = *arg1;
    *arg1 = (*arg1 + n * 0x90 + 0x3F) & 0xFFFFFFC0;
    arg0 += 0x10;
    if (D_00222500 != 0) {
        func_00453608(D_002224FC, 0, D_00222500 * 0x90);
    }
    for (i = 0; i < D_00222500; i++) {
        func_00453718(D_002224FC + i * 0x90, arg0, 0x90);
        arg0 += 0x80;
    }
}
