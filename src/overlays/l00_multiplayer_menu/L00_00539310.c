/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef union {
    unsigned long v;
} Type2;

typedef struct {
    Type2 *d;
    int top;
    int dmax;
    int neg;
} Type1;

extern Type1 *func_L00_005382C8(Type1 *a, int words);
extern int func_L00_005391C0(Type1 *a, unsigned long w);

int func_L00_00539310(Type1 *a, unsigned long w) {
    int i;
    unsigned long l;

    if (!w) return 1;
    if (a->neg) {
        a->neg = 0;
        i = func_L00_005391C0(a, w);
        a->neg = 1;
        return i;
    }
    if (a->top < 2) {
        if (a->top == 0) {
            if ((1 <= a->dmax ? a : func_L00_005382C8(a, 1)) == 0) return 0;
            a->d[0].v = w;
            a->neg = 1;
            a->top = 1;
            return 1;
        }
        l = a->d[0].v;
        if (l == w) {
            a->top = 0;
        } else if (l > w) {
            a->d[0].v = l - w;
        } else {
            a->neg = 1;
            a->d[0].v = w - l;
            return 1;
        }
    } else {
        i = 0;
        for (;;) {
            if (a->d[i].v >= w) {
                a->d[i].v -= w;
                break;
            } else {
                a->d[i].v -= w;
                i++;
                w = 1;
            }
        }
        if ((a->d[i].v == 0) && (i == (a->top - 1)))
            a->top--;
    }
    return 1;
}
