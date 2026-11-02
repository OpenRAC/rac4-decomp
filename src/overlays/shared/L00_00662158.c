#include "common.h"

extern s32 D_00222C08;
extern s32 D_00327998[];
extern void func_006215E8(s32);
extern void func_006229E0(s32);
extern void func_00623DB8(s32, s32, s32, s32);
extern void func_L00_00663148(void);

// Tear down the single entry: run func_00623DB8 with the key D_00222C08 and
// func_L00_00663148, release (func_006215E8) and clear the handles at +0x138C,
// +0x1390, +0x1394 and +0x139C of D_00327998, then run func_006229E0.
void func_L00_00662158(void) {
    func_00623DB8(0, 0, D_00222C08, 0);
    func_L00_00663148();
    if (D_00327998[0x138C / 4] != 0) {
        func_006215E8(D_00327998[0x138C / 4]);
        D_00327998[0x138C / 4] = 0;
    }
    if (D_00327998[0x1390 / 4] != 0) {
        func_006215E8(D_00327998[0x1390 / 4]);
        D_00327998[0x1390 / 4] = 0;
    }
    if (D_00327998[0x1394 / 4] != 0) {
        func_006215E8(D_00327998[0x1394 / 4]);
        D_00327998[0x1394 / 4] = 0;
    }
    if (D_00327998[0x139C / 4] != 0) {
        func_006215E8(D_00327998[0x139C / 4]);
        D_00327998[0x139C / 4] = 0;
    }
    func_006229E0(0);
}
