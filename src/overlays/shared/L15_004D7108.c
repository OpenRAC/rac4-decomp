#include "common.h"

typedef struct { s32 v[5]; } Arr5;
extern Arr5 D_003B16C0[];
extern Arr5 D_003B16D8[];

// Packs the set bit groups of a mask into a value using two constant tables.
s32 func_L15_004D7108(s32 arg0) {
    Arr5 a = D_003B16C0[0];
    Arr5 b = D_003B16D8[0];
    s32 r = 0;
    s32 t;

    if (arg0 & a.v[4]) {
        t = b.v[4];
        arg0 >>= t;
        r = t;
    }
    if (arg0 & a.v[3]) {
        t = b.v[3];
        arg0 >>= t;
        r |= t;
    }
    if (arg0 & a.v[2]) {
        t = b.v[2];
        arg0 >>= t;
        r |= t;
    }
    if (arg0 & a.v[1]) {
        t = b.v[1];
        arg0 >>= t;
        r |= t;
    }
    if (arg0 & a.v[0]) {
        r |= b.v[0];
    }
    return r;
}
