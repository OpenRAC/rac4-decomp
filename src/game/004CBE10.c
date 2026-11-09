#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 _p20[0x44];
} Type1;

extern void func_00499CE0(s32 arg0);
extern void func_0049B0D8(s32 arg0);
extern void func_0049C4B0(s32, s32, s32, s32);
extern void func_004CC780(void);
extern s32 func_00505B20(void);
extern s32 D_00221920;
extern Type1 D_0030EAA0[];

// Reset the current owner's entry: clear +8, notify, then free and clear the five handles at +0x10, +0xC, +0x14, +0x18, +0x1C.
void func_004CBE10(void) {
    s32 id = func_00505B20();
    Type1 *e = &D_0030EAA0[id];
    e->f8 = 0;
    func_0049C4B0(id, 0, D_00221920, 0);
    func_004CC780();
    if (e->f10 != 0) {
        func_00499CE0(e->f10);
        e->f10 = 0;
    }
    if (e->fC != 0) {
        func_00499CE0(e->fC);
        e->fC = 0;
    }
    if (e->f14 != 0) {
        func_00499CE0(e->f14);
        e->f14 = 0;
    }
    if (e->f18 != 0) {
        func_00499CE0(e->f18);
        e->f18 = 0;
    }
    if (e->f1C != 0) {
        func_00499CE0(e->f1C);
        e->f1C = 0;
    }
    func_0049B0D8(id);
}
