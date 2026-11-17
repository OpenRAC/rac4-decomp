/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 *f0; char _p4[0x14]; } E;
typedef struct { char _p0[0x188]; E *f188; char _p18c[0x10]; u16 f19C; char _p19e[0x3A]; u32 f1D8; } Obj;
s32 func_01EB8B60(Obj *o, u8 i, u16 j, s32 *out) {
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
    if (j >= o->f19C) {
        return 2;
    }
    if (t[i].f0[j] != 0) {
        *out = 1;
    }
    return 0;
}
