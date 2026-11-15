#include "common.h"

extern void func_L00_0076E478(void *arg0, s32 arg1);

typedef struct T1 {
    char pad[8];
    s32 f8;
    s32 fC;
    s32 f10;
} T1;

// Maps an error code to a state and advances the state machine.
void func_L00_0076E0E0(T1 *arg0, s32 *arg1) {
    s32 err = *arg1;

    if (err >= 0) {
        func_L00_0076E478(arg0, 1);
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
        func_L00_0076E478(arg0, 4);
    } else {
        func_L00_0076E478(arg0, 2);
    }
}
