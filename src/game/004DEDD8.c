#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 count;
    s16 mode;
    s16 unkA;
    u8 padC[2];
    s16 unkE;
} Type1;

void func_004DE880(s32, s32);
void func_004DEAE0(void);
void func_004DEBA0(s32, s32);
void func_004DF098(s32 arg0);
void func_004DF468(void);

extern s32 D_0021DDB4;
extern s32 D_0021DDB8;
extern Type1 *D_00221CF0;
extern s32 D_00221CFC;

void func_004DEDD8(void) {
    s32 active;
    s32 sel;
    s32 step;
    s32 i;

    active = 0;
    if (D_00221CF0->unkA != 0) {
        active = D_00221CF0->unkE >= 2;
    }
    sel = 0;
    if (active) {
        if (D_00221CF0->mode == 0) {
            func_004DE880(D_00221CF0->unkA, 0);
        } else {
            func_004DEAE0();
        }
        sel = D_0021DDB4 == 6;
    }
    step = D_0021DDB8 - D_00221CFC;
    if (step >= 3) {
        step = 2;
    }
    for (i = 0; i < D_00221CF0->count; i++) {
        func_004DEBA0(i, step);
        func_004DF098(i);
        if (active && i == sel) {
            func_004DF468();
        }
    }
    D_00221CFC = D_0021DDB8;
}
