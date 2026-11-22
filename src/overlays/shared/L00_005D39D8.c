/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00453608(s32, s32, s32);
extern void func_00453718(s32, void *, s32);
extern s32 D_00222504;
extern s32 D_00222508;

void func_L00_005D39D8(u8 *arg0, s32 *arg1) {
    s32 i;
    s32 n;

    n = *(s32 *)arg0;
    D_00222508 = n;
    D_00222504 = *arg1;
    *arg1 = (*arg1 + (n << 7) + 0x3F) & 0xFFFFFFC0;
    arg0 += 0x10;
    if (D_00222508 != 0) {
        func_00453608(D_00222504, 0, D_00222508 << 7);
    }
    for (i = 0; i < D_00222508; i++) {
        func_00453718(D_00222504 + (i << 7), arg0, 0x80);
        arg0 += 0x80;
    }
}
