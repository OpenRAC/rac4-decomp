#include "common.h"
/* Ported from rac3-decomp's func_L01_00474328 (src/levels/shared/L01_004729D8.c, GPL-3.0), the same code in both games. */

typedef struct Ops_45E458 Ops_45E458;
typedef struct {
    s32 pad;
    Ops_45E458 *ops;
} Sub_45E458;
struct Ops_45E458 {
    s32 pad[5];
    void (*fn)(u8 *a0, Sub_45E458 *s);
};
extern s32 func_00453508(void *p);
extern void func_00490AC8(u8 *a0);
void func_L00_0061A5B0(u8 *a0)
{
    Sub_45E458 *s = (Sub_45E458 *)(a0 + 32);
    if (s != 0) {
        if (func_00453508(a0 + 10)) {
            func_00490AC8(a0);
        } else if (s->ops != 0) {
            s->ops->fn(a0, s);
        }
    }
}
extern void func_00490AC8(u8 *);
