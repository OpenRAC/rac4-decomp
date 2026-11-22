#include "common.h"
typedef struct C { char _p0[0xBC]; s16 fBC; } C;
typedef struct B { char _p0[0x2B0]; C *f2B0; } B;
typedef struct A { char _p0[0x2EF0]; s32 f2EF0; B *f2EF4; } A;
typedef struct T2 { char _p0[0x320]; s32 f320; } T2;
typedef struct T1 { char _p0[0xAC]; T2 *fAC; } T1;
extern A *D_003660F8[10];
s32 func_L01_0045A430(T1 *arg0) {
    T2 *p = arg0->fAC;
    s32 i;
    A **q;
    A *a;
    if (p->f320 == 0) return 0;
    q = D_003660F8;
    a = *q;
 for (i = 0; i < 10; i++) {
 if (a != 0 && a->f2EF0 == p->f320 && a->f2EF4 != 0 && a->f2EF4->f2B0 != 0 && a->f2EF4->f2B0->fBC == 0x20AE) return 1;
 q++;
 a = *q;
 }
 return 0;
}
