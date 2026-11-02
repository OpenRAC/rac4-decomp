#include "common.h"

// Store arg1 at pvar+0x1A2; in states 7-9 with pvar+0x283 set, send event 5 (states 7, 9) or 1.

typedef struct Type2 {
    char _p0[0x19C];
    s32 f19C;
    char _p1A0[0x1A2 - 0x1A0];
    u8 f1A2;
    char _p1A3[0x283 - 0x1A3];
    u8 f283;
} Type2;

typedef struct Type1 {
    char _p0[0x20];
    u8 f20;
    char _p21[0xAC - 0x21];
    Type2 *fAC;
} Type1;

extern void func_00591BD8(Type1 *arg0, s32 arg1, s32 arg2);

void func_L01_004BBFC0(Type1 *arg0, u8 arg1) {
    Type2 *p = arg0->fAC;

    p->f1A2 = arg1;
    if (p->f283 != 0 && (u32)(arg0->f20 - 7) < 3) {
        p->f19C = 3;
        if (arg0->f20 == 7 || arg0->f20 == 9) {
            func_00591BD8(arg0, 5, -1);
        } else {
            func_00591BD8(arg0, 1, -1);
        }
    }
}
