/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4; void *f8; } Arr;
s32 func_004105C0(s32, Arr *);
extern void func_00403330(void *, void *, u32);
s32 func_0040EA70(Arr *src, Arr *dst) {
    s32 n = src->f4;
    s32 r;
    if (dst->f0 < n) {
        r = func_004105C0(n, dst);
        if (r != 0) {
            return r;
        }
    }
    func_00403330(dst->f8, src->f8, n * 8);
    dst->f4 = n;
    return 0;
}
