/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    unsigned long *d;
    int top;
    int dmax;
} Type1;

extern void func_L00_00538128(Type1 *a);
extern Type1 *func_L00_00538190(void);
extern Type1 *func_L00_005382C8(Type1 *a, int words);

Type1 *func_L00_00538590(unsigned char *s, int len, Type1 *ret) {
    unsigned int i, m;
    unsigned int n;
    unsigned long l;

    if (ret == 0) ret = func_L00_00538190();
    if (ret == 0) return 0;
    l = 0;
    n = len;
    if (n == 0) {
        ret->top = 0;
        return ret;
    }
    if (((((int)(n + 2) + 7) / 8) <= ret->dmax ? ret : func_L00_005382C8(ret, (int)(n + 2) / 8 + 1)) == 0) return 0;
    i = ((n - 1) / 8) + 1;
    m = ((n - 1) % 8);
    ret->top = i;
    while (n-- > 0) {
        l = (l << 8) | *(s++);
        if (m-- == 0) {
            { unsigned long *d = ret->d; d[--i] = l; }
            l = 0;
            m = 8 - 1;
        }
    }
    func_L00_00538128(ret);
    return ret;
}
