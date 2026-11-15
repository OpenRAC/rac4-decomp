#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
} T1;
typedef struct {
    u8 pad0[0x1DC];
    s32 f1DC;
    s32 f1E0;
} T2;
extern void func_L00_0076E478(void *arg0, s32 arg1);

// Maps an error code to a state and advances the state machine.
void func_L00_0076E3C0(T1 *arg0, T2 *arg1) {
    s32 err = arg1->f1E0;

    if (err >= 0) {
        if (arg1->f1DC == 3) {
            func_L00_0076E478((void *)arg0, 2);
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
        func_L00_0076E478((void *)arg0, 7);
    } else {
        func_L00_0076E478((void *)arg0, 2);
    }
}
