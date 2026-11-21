/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct { s32 cap; s32 n; s64 *d; } S;
extern s32 func_004104C8(s32, S *);
extern s32 func_00403358(void *, void *, s32);
s32 func_00411658(s64 x, S *s) {
    s32 n = s->n;
    s64 *d = s->d;
    s32 bytes = n * 8;
    s32 r;
    if (d[n - 1] != 0) {
        if (s->cap < n + 1) {
            r = func_004104C8(n + 2, s);
            if (r != 0) {
                return r;
            }
        }
        func_00403358(s->d + 1, s->d, bytes);
        s->d[0] = x;
        s->n++;
        return 0;
    }
    d[0] = x;
    s->n = 1;
    return 0;
}
