/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Pool {
    s32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u8 *f10;
    u8 *f14;
} Pool;

extern void func_0011A518(void *, s32, s32);
extern s32 func_01EA94D0(u8 **, u64);

s32 func_01EB5FB0(Pool *p, u32 size, u32 elem) {
    s32 ret;

    if (p == NULL) {
        return 2;
    }
    if (size & 3) {
        return 2;
    }
    if (elem & 3) {
        return 2;
    }
    if (elem >= size) {
        return 2;
    }
    func_0011A518(p, 0, 0x18);
    ret = func_01EA94D0(&p->f10, size);
    if (ret != 0) {
        return ret;
    }
    p->f4 = size;
    p->f8 = elem;
    p->f0 = 0;
    p->fC = size / elem;
    if (size % elem < p->fC) {
        p->fC = p->fC - (p->fC - size % elem) / elem;
    }
    p->f14 = p->f10 + p->fC * p->f8;
    func_0011A518(p->f14, 0, p->fC);
    return 0;
}
