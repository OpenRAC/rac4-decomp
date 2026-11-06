#include "common.h"

extern void func_004494E8(s32 a, s32 b);
extern void func_00453608(void *p, s32 v, s32 n);
extern void func_00489030(s32 a, s32 b, s32 c);
extern void func_00489478(void);
extern void func_004E7638(void);
extern s32 D_00171FC8[];
extern s32 D_0021EDC4;
extern void (*D_0021EE10)(s32);
extern s32 D_0021EE14;
extern u8 D_001D2200[];
extern s32 D_0021DAD8;
extern s32 D_00221E14;
extern s32 D_0023A860_[];
#define D_0023A860 (D_0023A860_[0])

/* Init sequence, then run and clear a pending callback when allowed */
void func_004E4FA0(void) {
    void (*cb)(s32);

    if (D_0021DAD8 == 0) {
        D_0021DAD8 = 1;
    }
    func_004494E8(4, 0);
    func_00453608(D_00171FC8, 0x400, 0x18);
    func_00489030(D_00221E14, 1, 0x400);
    func_00489478();
    D_001D2200[0x43] |= 0x10;
    func_004E7638();
    cb = D_0021EE10;
    if (cb != 0 && D_0023A860 == 0 && D_0021EDC4 != 2 && D_0021EDC4 != 1) {
        cb(D_0021EE14);
        D_0021EE10 = 0;
        D_0021EE14 = 0;
    }
}
