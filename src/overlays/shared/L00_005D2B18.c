#include "common.h"

s32 D_0021E960 = 0;
s32 D_0021E944 = 0;
s32 D_0021E954 = 0;
s32 D_0021E95C = 0;
s32 D_0021E958 = 0;
s32 D_0021E964 = 0;
s32 D_00222454 = 0;

extern s32 D_0021E6B4;
extern s32 D_00244218[];
extern s32 D_002442D8[];
extern void func_L00_005BCAE0(void *, s32, s32);
extern s32 func_L00_005D2B10(s32, s32);

void func_L00_005D2B18(s32 *arg0, s32 arg1, s32 *arg2) {
    s32 *p;
    s32 s0;
    s32 t;

    s0 = arg0[0];
    p = arg0 + 2;
    D_0021E960 = arg0[1];
    if (D_0021E6B4 == 1) {
        D_0021E960 = 0x1F4;
    }
    D_0021E958 = 0;
    D_0021E95C = s0;
    t = *arg2;
    D_0021E964 = (D_0021E960 + D_0021E954) << 8;
    D_00222454 = t;
    func_L00_005BCAE0((void *)t, 0, (s0 + D_0021E944 + D_0021E960 + D_0021E954) << 8);
    D_0021E958 = func_L00_005D2B10((s32)p, s0);
    func_L00_005BCAE0(D_00244218, 0, 0xC0);
    func_L00_005BCAE0(D_002442D8, 0, 0xC0);
}
