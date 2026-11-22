/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00453608(s32, s32, s32);
extern void func_00453718(s32, void *, s32);
extern s32 D_002224E0;
extern s32 D_002224E4;

void func_L00_005D3910(u8 *arg0, s32 *arg1) {
    s32 i;
    s32 n;

    n = *(s32 *)arg0;
    D_002224E4 = n;
    D_002224E0 = *arg1;
    *arg1 = (*arg1 + (n << 7) + 0x3F) & 0xFFFFFFC0;
    arg0 += 0x10;
    if (D_002224E4 != 0) {
        func_00453608(D_002224E0, 0, D_002224E4 << 7);
    }
    for (i = 0; i < D_002224E4; i++) {
        func_00453718(D_002224E0 + (i << 7), arg0, 0x80);
        arg0 += 0x80;
    }
}
