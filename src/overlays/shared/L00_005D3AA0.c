/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00453608(s32, s32, s32);
extern void func_00453718(s32, void *, s32);
extern s32 D_0022250C;
extern s32 D_00222510;

void func_L00_005D3AA0(u8 *arg0, s32 *arg1) {
    s32 i;
    s32 n;

    n = *(s32 *)arg0;
    D_00222510 = n;
    D_0022250C = *arg1;
    *arg1 = (*arg1 + (n << 7) + 0x3F) & 0xFFFFFFC0;
    arg0 += 0x10;
    if (D_00222510 != 0) {
        func_00453608(D_0022250C, 0, D_00222510 << 7);
    }
    for (i = 0; i < D_00222510; i++) {
        func_00453718(D_0022250C + (i << 7), arg0, 0x80);
        arg0 += 0x80;
    }
}
