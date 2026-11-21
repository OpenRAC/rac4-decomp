/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00538128(void *p);
extern int func_L00_005382C8(int a1, int a2);
extern s32 func_L00_00538508(void *a0, void *a1);

/* shifts the bignum a right by n bits into r */
s32 func_L00_00547558(u8 *r, u8 *a, s32 n) {
    s32 nw;
    s32 rb;
    s32 lb;
    s32 top;
    s32 len;
    s32 need;
    s32 i;
    u64 *ap;
    u64 *rp;
    u64 w;

    rb = n / 64;
    nw = rb;
    rb = n - (nw << 6);
    lb = 64 - rb;
    top = *(s32 *)(a + 4);
    if (top < nw) {
        func_L00_00538508(r, 0);
        return 1;
    }
    if (r != a) {
        need = top - nw + 2;
        if ((*(s32 *)(r + 8) < need ? (u8 *)func_L00_005382C8((int)r, need) : r) == 0) {
            return 0;
        }
        *(s32 *)(r + 0xC) = *(s32 *)(a + 0xC);
        top = *(s32 *)(a + 4);
    }
    len = top - nw;
    rp = *(u64 **)r;
    ap = (u64 *)(*(u8 **)a + nw * 8);
    *(s32 *)(r + 4) = len;
    if (rb == 0) {
        for (i = len + 1; i > 0; i--) {
            *rp++ = *ap++;
        }
    } else {
        w = *ap++;
        for (i = 1; i < len; i++) {
            u64 v = w >> rb;
            w = *ap++;
            *rp++ = v | (w << lb);
        }
        rp[1] = 0;
        rp[0] = w >> rb;
    }
    func_L00_00538128(r);
    return 1;
}
