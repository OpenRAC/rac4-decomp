/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 f10; } In;
typedef struct { In *f0; void *f4; } Obj;
extern void func_0011A370(void *, void *, s32);
s32 func_01ED90D8(Obj *a, Obj *b) {
    if (a == 0) {
        return -0x15;
    }
    if (b == 0) {
        return -0x15;
    }
    if (a->f0 == 0) {
        return -0x15;
    }
    if (a->f0 != b->f0) {
        return -0x15;
    }
    if (a->f4 == 0) {
        return -0x15;
    }
    if (b->f4 == 0) {
        return -0x15;
    }
    if (a->f0->f10 == 0) {
        return -0x15;
    }
    func_0011A370(a->f4, b->f4, a->f0->f10);
    return 0;
}
