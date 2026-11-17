/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 f10; } In;
typedef struct { In *f0; void *f4; } Obj;
extern void func_0011A370(void *, void *, s32);
s32 func_01ED91C8(Obj *o, void *dst, s32 n) {
    if (o == 0) {
        return -0x15;
    }
    if (dst == 0) {
        return -0x15;
    }
    if (o->f0 == 0) {
        return -0x15;
    }
    if (o->f4 == 0) {
        return -0x15;
    }
    if (o->f0->f10 == 0) {
        return -0x15;
    }
    if (o->f0->f10 != n) {
        return -0x15;
    }
    func_0011A370(o->f4, dst, n);
    return 0;
}
