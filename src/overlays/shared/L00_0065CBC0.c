#include "common.h"

extern s32 D_00222A88;
extern s32 D_003217B8[];
extern void func_006215E8(s32);
extern void func_006229E0(s32);
extern void func_00623DB8(s32, s32, s32, s32);
extern void func_L00_0065DBA8(void);

// Tear down the single entry: run func_00623DB8 with the key D_00222A88 and
// func_L00_0065DBA8, release (func_006215E8) and clear the handles at +0x138C,
// +0x1390, +0x1394 and +0x139C of D_003217B8, then run func_006229E0.
void func_L00_0065CBC0(void) {
    func_00623DB8(0, 0, D_00222A88, 0);
    func_L00_0065DBA8();
    if (D_003217B8[0x138C / 4] != 0) {
        func_006215E8(D_003217B8[0x138C / 4]);
        D_003217B8[0x138C / 4] = 0;
    }
    if (D_003217B8[0x1390 / 4] != 0) {
        func_006215E8(D_003217B8[0x1390 / 4]);
        D_003217B8[0x1390 / 4] = 0;
    }
    if (D_003217B8[0x1394 / 4] != 0) {
        func_006215E8(D_003217B8[0x1394 / 4]);
        D_003217B8[0x1394 / 4] = 0;
    }
    if (D_003217B8[0x139C / 4] != 0) {
        func_006215E8(D_003217B8[0x139C / 4]);
        D_003217B8[0x139C / 4] = 0;
    }
    func_006229E0(0);
}
