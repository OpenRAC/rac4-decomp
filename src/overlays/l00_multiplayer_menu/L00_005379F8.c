/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    unsigned long *d;
    int top;
    int dmax;
} Type1;

extern void func_L00_00538128(Type1 *a);
extern Type1 *func_L00_005382C8(Type1 *a, int words);

int func_L00_005379F8(Type1 *r, Type1 *a, Type1 *b) {
    int max, min;
    unsigned long t1, t2, *ap, *bp, *rp;
    int i, carry;

    if (a->top < b->top) {
        return 0;
    }
    max = a->top;
    min = b->top;
    if (((max <= r->dmax) ? r : func_L00_005382C8(r, max)) == 0) return 0;

    ap = a->d;
    bp = b->d;
    rp = r->d;

    carry = 0;
    for (i = 0; i < min; i++) {
        t1 = *(ap++);
        t2 = *(bp++);
        if (carry) {
            carry = (t1 <= t2);
            t1 = (t1 - t2 - 1);
        } else {
            carry = (t1 < t2);
            t1 = (t1 - t2);
        }
        *(rp++) = t1;
    }
    if (carry) {
        while (i < max) {
            i++;
            t1 = *(ap++);
            t2 = (t1 - 1);
            *(rp++) = t2;
            if (t1 > t2) break;
        }
    }
    if (rp != ap) {
        for (;;) {
            if (i++ >= max) break;
            rp[0] = ap[0];
            if (i++ >= max) break;
            rp[1] = ap[1];
            if (i++ >= max) break;
            rp[2] = ap[2];
            if (i++ >= max) break;
            rp[3] = ap[3];
            rp += 4;
            ap += 4;
        }
    }
    r->top = max;
    func_L00_00538128(r);
    return 1;
}
