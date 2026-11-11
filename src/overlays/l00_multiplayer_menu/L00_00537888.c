/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef union Type2 { u64 q; int i; } Type2;

typedef struct Type1 {
    int d;
    int top;
    int dmax;
} Type1;

extern int func_L00_005382C8(Type1 *a1, int a2);
extern u64 func_L00_00539E30(u64 *, u64 *, u64 *, int);

int func_L00_00537888(Type1 *r, Type1 *a, Type1 *b)
{
    int i;
    int max, min;
    u64 *ap, *bp, *rp, carry, t1;
    Type1 *tmp;

    if (a->top < b->top) {
        tmp = a; a = b; b = tmp;
    }
    max = a->top;
    min = b->top;

    if ((max + 1 <= r->dmax ? (int)r : func_L00_005382C8(r, max + 1)) == 0)
        return 0;

    r->top = max;

    ap = (u64 *)a->d;
    bp = (u64 *)b->d;
    rp = (u64 *)r->d;
    carry = 0;

    carry = func_L00_00539E30(rp, ap, bp, min);
    rp += min;
    ap += min;
    bp += min;
    i = min;

    if (carry) {
        while (i < max) {
            i++;
            t1 = *(ap++);
            if ((*(rp++) = t1 + 1) >= t1) {
                carry = 0;
                break;
            }
        }
        if (i >= max && carry) {
            *(rp++) = 1;
            ((Type2 *)&r->top)->i++;
        }
    }
    if (rp != ap) {
        for (; i < max; i++)
            *(rp++) = *(ap++);
    }
    return 1;
}
