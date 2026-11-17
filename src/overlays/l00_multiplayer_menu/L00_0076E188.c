#include "common.h"

extern void func_L00_0076E478(void *arg0, s32 arg1);

typedef struct T1 {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
    u8 *f14;
    u32 f18;
    u32 f1C;
} T1;

typedef struct T2 {
    u8 b[0x1D0];
    s32 f1D0;
    s32 f1D4;
    s32 pad1D8;
    s32 f1DC;
    s32 f1E0;
} T2;

// Copies bytes from a ring buffer into an output buffer, or maps an error code to a state.
void func_L00_0076E188(T1 *arg0, T2 *arg1) {
    s32 err = arg1->f1E0;
    s32 i;

    if (err >= 0) {
        for (i = 0; i < arg1->f1D4; i++) {
            if (arg0->f1C < arg0->f18) {
                arg0->f14[arg0->f1C] = arg1->b[(arg1->f1D0 + i) % 464];
            }
            arg0->f1C++;
        }
        if (arg1->f1DC == 3) {
            func_L00_0076E478((void *)arg0, 1);
        }
        return;
    }
    if (err == -0x3C4) {
        arg0->f10 = 0x29;
    } else if (err == -0x3C3) {
        arg0->f10 = 0x2F;
    } else if (err == -0x3C2) {
        arg0->f10 = 0x2A;
    } else if (err == -0x3C1) {
        arg0->f10 = 0x2B;
    } else if (err == -0x3C0) {
        arg0->f10 = 0x2E;
    } else {
        arg0->f10 = 0x28;
    }
    if (arg0->f8 != 0) {
        func_L00_0076E478((void *)arg0, 5);
    } else {
        func_L00_0076E478((void *)arg0, 1);
    }
}
