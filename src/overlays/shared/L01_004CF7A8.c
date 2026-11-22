#include "common.h"
typedef struct Q { char _p[0x2DD]; u8 f2DD; char _q; u8 f2DF; s32 f2E0; } Q;
typedef struct E { char _p[0xAC]; Q *fAC; char _q[0xBC - 0xB0]; s16 fBC; char _r[0x100 - 0xBE]; } E;
extern E *D_00222D14;
extern E *D_00222D30;
extern s32 func_00472560(s32);
extern void func_L01_004CF658(void *, s32);
s32 func_L01_004CF7A8(void) {
    E *list[16];
    E *p;
    s32 n = 0;
    s32 r = 0;
    s32 ok = 1;
    for (p = D_00222D14; p != D_00222D30; p++) {
        if (p->fBC == 0x2075) {
            Q *q = p->fAC;
            if (q->f2E0 == 0) {
                ok = 0;
                break;
            }
            if (q->f2DF == 0 && q->f2DD != 0) {
                list[n++] = p;
            }
        }
    }
    if (!ok) return 0;
    if (n != 0) {
        func_L01_004CF658(list[func_00472560(n)], 0);
        r = 1;
    }
    return r;
}
