/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[4]; s32 f4; char _p8[8]; u32 f10; } In;
typedef struct { In *f0; void *f4; } Obj;
extern void func_0011A370(void *, void *, s32);
s32 func_01ED9148(Obj *o, void *dst, u32 n) {
    In *in;
    if (o == 0) {
        return -0x15;
    }
    if (dst == 0) {
        return -0x15;
    }
    in = o->f0;
    if (in == 0) {
        return -0x15;
    }
    if (o->f4 == 0) {
        return -0x15;
    }
    if (in->f10 == 0) {
        return -0x15;
    }
    if (in->f4 == 0xB) {
        if (n < in->f10) {
            return -0x15;
        }
    } else if (in->f10 != n) {
        return -0x15;
    }
    func_0011A370(dst, o->f4, n);
    return 0;
}
