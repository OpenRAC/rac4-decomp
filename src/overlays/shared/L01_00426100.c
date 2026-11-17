#include "common.h"

typedef struct {
    u8 pad0[0x14];
    s32 f14;
    u8 pad18[7];
    u8 f1F;
    u8 f20;
    u8 pad21[0x1F];
    s32 f40[1];
} T2;
typedef struct {
    u8 pad0[0xAC];
    T2 *fAC;
} T1;
extern void func_L00_005CBF20(s32);
extern void func_L00_005DD4A0(void *);
extern void func_L00_00607960(s32);
extern s32 D_223814;

// Releases the slots of an object's sub-record and hands the object on.
void func_L01_00426100(T1 *arg0) {
    T2 *p = arg0->fAC;
    s32 i;

    for (i = 0; i < p->f1F; i++) {
        if (p->f40[i] != 0) {
            func_L00_00607960(p->f40[i]);
            p->f40[i] = 0;
        }
    }
    if (p->f14 >= 0) {
        func_L00_005CBF20(p->f14);
        p->f14 = -1;
    }
    if (D_223814 == (s32)arg0) {
        ((T2 *)arg0)->f20 = 3;
    } else {
        func_L00_005DD4A0(arg0);
    }
}
