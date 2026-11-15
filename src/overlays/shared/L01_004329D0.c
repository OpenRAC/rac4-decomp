#include "common.h"

typedef struct Sub {
    char pad0[4];
    s16 f4;
    s16 f6;
} Sub;

typedef struct Type1 {
    char pad0[0xAC];
    Sub *fAC;
} Type1;

extern void func_L01_004320A8(Type1 *);
extern void func_L01_004324A0(Type1 *);

void func_L01_004329D0(Type1 *arg0) {
    Sub *s = arg0->fAC;

    if (s->f6 > 0) {
        func_L01_004320A8(arg0);
    }
    if (s->f4 > 0) {
        func_L01_004324A0(arg0);
    }
}
