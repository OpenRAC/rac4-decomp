/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u32 func_0011AB04(const char *);
extern char *func_01EE3DB0(void *, u32);
extern void *func_0011A370(void *, const void *, u32);
char *func_01EE3E14(void *pool, const char *s, u32 n) {
    char *d;
    if (s == 0) {
        return 0;
    }
    if (n == 0) {
        n = func_0011AB04(s);
    }
    d = func_01EE3DB0(pool, n + 1);
    if (d == 0) {
        return 0;
    }
    func_0011A370(d, s, n);
    d[n] = 0;
    return d;
}
