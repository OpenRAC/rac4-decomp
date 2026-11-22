#include "common.h"
typedef struct E { char _p[0xBC]; s16 fBC; } E;
typedef struct S {
    char _p0[0x28]; E *f28; E *f2C;
    char _p1[0x2C0 - 0x30]; E *f2C0; E *f2C4;
    char _p2[0x2E4 - 0x2C8]; u8 f2E4;
} S;
typedef struct O { char _p[0xAC]; S *fAC; } O;
typedef struct Tbl { char _p[0x594]; u8 a594[0x14]; u8 a5A8[0x14]; } Tbl;
extern Tbl D_0038EAC0;
extern void func_L01_004CFDA0(E *);
extern void func_L01_004D2D00(E *);
void func_L01_004CEFF0(O *o) {
    S *s = o->fAC;
    if (s->f28) {
        if (s->f2E4 != 10 && D_0038EAC0.a5A8[s->f2E4] == 1) {
            if (s->f28->fBC == 0x20C7 || s->f28->fBC == 0x2107 || s->f28->fBC == 0x2557) {
                func_L01_004CFDA0(s->f28);
                func_L01_004CFDA0(s->f2C);
            }
        } else {
            if (s->f28->fBC == 0x1A63 || s->f28->fBC == 0x2555 || s->f28->fBC == 0x2556) {
                func_L01_004D2D00(s->f28);
                func_L01_004D2D00(s->f2C);
            }
        }
    }
    if (s->f2C0 && s->f2E4 != 10 && D_0038EAC0.a594[s->f2E4] == 1) {
        if (s->f2C0->fBC == 0x1A63 || s->f2C0->fBC == 0x2555 || s->f2C0->fBC == 0x2556) {
            func_L01_004D2D00(s->f2C0);
            func_L01_004D2D00(s->f2C4);
        }
    }
}
