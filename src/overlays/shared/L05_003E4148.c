#include "common.h"

extern void *func_L00_005F2FB8(void);
extern f32 func_L05_003E4210();
extern u8 *D_363038[];

/* returns the largest value over two tables of objects */
f32 func_L05_003E4148(s32 arg0, f32 best) {
    s32 i;
    u8 **p = D_363038;
    f32 v;
    u8 *o = *p;
    for (i = 9; i >= 0; i--) {
        if (o != 0) {
            v = func_L05_003E4210(arg0, *(s32 *)(o + 0x2EF0));
            if (best < v) best = v;
        }
        p++;
        o = *p;
    }
    for (i = 0; i < 4; i++) {
        s32 a = *(s32 *)((u8 *)func_L00_005F2FB8() + (i << 2) + 0x1D0);
        if (a != 0) {
            v = func_L05_003E4210(arg0, a);
            if (best < v) best = v;
        }
    }
    return best;
}
