#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 _pC[0x58];
} Type1;

extern s32 func_00497580(s32 *, s32, s32 (*)(s32));
extern s32 func_00497628(s32 *, s32, s32 (*)(s32));
extern void func_00497980(s32 arg0);
extern s32 func_004CC0B8(s32 arg0);
extern void func_004CC100(s32 arg0);
extern void func_004CC148(s32 selection);
extern s32 func_00505B20(void);
extern Type1 D_0030EAA0[];

void func_004CC2E8(s32 mode) {
    Type1 *e = &D_0030EAA0[func_00505B20()];
    s32 changed;

    if (e->f4 < 0) {
        return;
    }
    func_004CC100(e->f4);
    switch (mode) {
    case 0:
        e->f4--;
        changed = func_00497580(&e->f4, 0xC, func_004CC0B8);
        break;
    case 1:
        e->f4++;
        changed = func_00497628(&e->f4, 0xC, func_004CC0B8);
        break;
    case 3:
        changed = func_00497628(&e->f4, 0xC, func_004CC0B8);
        break;
    case 2:
        changed = func_00497580(&e->f4, 0xC, func_004CC0B8);
        break;
    default:
        changed = 0;
        break;
    }
    if (changed != 0) {
        func_004CC148(e->f4);
        func_00497980(0xF);
        e->f8 |= 1;
    }
}
