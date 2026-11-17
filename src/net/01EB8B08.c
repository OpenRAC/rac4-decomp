/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 f10; char _p14[4]; } E;
typedef struct { char _p0[0x188]; E *f188; char _p18c[0x4C]; u32 f1D8; } Obj;
s32 func_01EB8B08(Obj *o, u8 i, s32 *out) {
    E *t;
    if (out == 0) {
        return 2;
    }
    *out = 0;
    if (o == 0) {
        return 2;
    }
    if (i >= o->f1D8) {
        return 2;
    }
    t = o->f188;
    if (t == 0) {
        return 3;
    }
    *out = t[i].f10;
    return 0;
}
