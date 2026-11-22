#include "common.h"
typedef struct VT { f32 (*fn)(void *); } VT;
typedef struct P { char _p[0xC]; void *fC; VT *f10; } P;
typedef struct O { char _p[0xAC]; P *fAC; } O;
s32 func_L01_004CF118(O *o) {
    s32 r = 0;
    P *p = o->fAC;
    if (p) {
        if (p->f10 && p->fC) {
            if (p->f10->fn(p->fC) >= 1.0f) r = 1;
        }
    }
    return r;
}
