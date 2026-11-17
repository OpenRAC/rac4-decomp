#include "common.h"

extern s32 func_00138D70(s32);
extern void func_0015ADA8(void);
extern void func_00161CF0(void);
extern void func_00447938(void);
extern void func_00448720(void);
extern void func_004494E8(s32, s32);
extern void func_00459430(void);
extern void func_004594C8(s32);
extern void func_004596E0(void);
extern void func_004597B8(s32 alternate);
extern s32 func_004636C8(void);
extern void func_00464B60(void);
extern void func_00466310(void);
extern void func_004692C8(s32, s32);
extern void func_00490878(void);
extern void func_004E7688(void);
extern void func_004E7708(void);
extern void func_004E7830(s32 mask);
extern void func_004F35B0(s32 arg0);
extern s32 func_004F3800(s32 value);
extern void func_004F3B78(void);
extern s32 func_004F3DA8(void);
extern void func_004F43C0(void);
extern void func_004F5428(void);
extern s32 D_0021EDD4;
extern u8 D_0021EE18;
extern s32 D_21DA20;
extern s32 D_2211CC;
extern s32 D_2212E0;
u8 D_00220950 = 0;
s8 D_00220951 = 0;
u8 D_00220974 = 0;
u8 D_00220975 = 0;
s32 D_00220980 = 0;
s32 D_00221328 = 0;

// Runs the frame loop of the mode until it finishes, then hands over to the next stage.
s32 func_004F4558(void) {
    s32 s0;

    if (D_0021EDD4 != 1) {
        if (D_0021EE18 == 0) {
            func_004692C8(0, D_2212E0);
        }
    }
    if (D_0021EDD4 == 1) {
        func_00161CF0();
        func_0015ADA8();
    }
    if (D_2212E0 < 0) {
        func_004F3B78();
        return 1;
    }
    if (D_0021EDD4 == 1) {
        func_00161CF0();
        func_0015ADA8();
    }
    func_004F3DA8();
    if (D_0021EDD4 == 1) {
        func_00161CF0();
        func_0015ADA8();
    }
    D_00220950 = 0;
    D_00220951 = 0;
    do {
        func_004E7708();
        func_004E7688();
        func_004596E0();
        if (D_00220974 != 0) {
            func_004F5428();
        } else {
            func_004597B8(1);
        }
        func_00459430();
        func_004594C8(0);
        func_00448720();
        func_00490878();
        if (D_0021EDD4 == 1) {
            func_00161CF0();
            func_0015ADA8();
        }
        s0 = func_004F3800(D_00220950);
        D_00221328 = 0;
        func_00447938();
        func_004F35B0(D_00220950);
        func_00466310();
        func_00464B60();
        func_004E7830(1);
        func_00138D70(0);
        D_2211CC = D_2211CC + 1;
        if (D_00220980 == 0) {
            D_00220951 = func_004636C8() != 0;
        }
        D_00220950 = D_21DA20 >= 10;
    } while (s0 == 0);
    if (D_0021EDD4 == 1) {
        func_00161CF0();
        func_0015ADA8();
    }
    if (D_00220975 == 0) {
        func_004494E8(6, 0);
    }
    if (D_0021EDD4 == 1) {
        func_00161CF0();
        func_0015ADA8();
    }
    func_004F43C0();
    return 1;
}
