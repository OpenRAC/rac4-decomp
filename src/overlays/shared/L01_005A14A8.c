/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 *D_00222C18[];
extern u8 *D_00222C14[];
extern void func_L01_005A1370(s32);

/* from rac3-decomp's func_L10_004399A0 */
s32 func_L01_005A14A8(s32 a, s32 n) {
    s32 i;
    u8 *rec;
    s32 *p;
    s32 cnt;
    s32 *q;
    if (n >= 0) {
        q = D_00222C18[0];
        if (!(n < q[0])) {
            return 0;
        }
    } else {
        return 0;
    }
    func_L01_005A1370(n);
    p = (s32 *)(D_00222C14[0] + n * 0xE0);
    cnt = ((u8 *)p)[4];
    if (cnt == 0) {
        return 0;
    }
    for (i = 0; i < cnt; i++) {
        if (p[0] != 0 && p[0] == a) {
            return 1;
        }
        p += 2;
    }
    return 0;
}
