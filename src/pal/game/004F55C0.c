#include "common.h"

extern s32 D_0021EE54;
extern u8 D_0021EE98;
extern s32 D_002213E0;
extern s32 D_002212CC;
extern s32 D_0021DAA0;
extern s32 D_00221428;
u8 D_002209F0 = 0;
u8 D_002209F1 = 0;
u8 D_00220A14 = 0;
u8 D_00220A15 = 0;
s32 D_00220A20 = 0;

void func_00469B80(s32, s32);
void func_00161D00(void);
void func_0015ADC8(void);
void func_004F4BE0(void);
s32 func_004F4E10(void);
void func_004E8630(void);
void func_004E85B0(void);
void func_00459EF8(void);
void func_004F64A8(void);
void func_00459FD0(s32);
void func_00459C48(void);
void func_00459CE0(s32);
void func_00448D60(void);
void func_00491360(void);
s32 func_004F4868(s32);
void func_00447F78(void);
void func_004F4618(s32);
void func_00466B58(void);
void func_004653A0(void);
void func_004E8758(s32);
s32 func_00138D70(s32);
s32 func_00463F08(void);
void func_00449B28(s32, s32);
void func_004F5428(void);

// Add PAL C for func_004F55C0
s32 func_004F55C0(void) {
    s32 done;

    if (D_0021EE54 != 1 && D_0021EE98 == 0) {
        func_00469B80(0, D_002213E0);
    }
    if (D_0021EE54 == 1) {
        func_00161D00();
        func_0015ADC8();
    }
    if (D_002213E0 < 0) {
        func_004F4BE0();
        return 1;
    }
    if (D_0021EE54 == 1) {
        func_00161D00();
        func_0015ADC8();
    }
    func_004F4E10();
    if (D_0021EE54 == 1) {
        func_00161D00();
        func_0015ADC8();
    }
    D_002209F0 = 0;
    D_002209F1 = 0;
    do {
        func_004E8630();
        func_004E85B0();
        func_00459EF8();
        if (D_00220A14 != 0) {
            func_004F64A8();
        } else {
            func_00459FD0(1);
        }
        func_00459C48();
        func_00459CE0(0);
        func_00448D60();
        func_00491360();
        if (D_0021EE54 == 1) {
            func_00161D00();
            func_0015ADC8();
        }
        done = func_004F4868(D_002209F0);
        D_00221428 = 0;
        func_00447F78();
        func_004F4618(D_002209F0);
        func_00466B58();
        func_004653A0();
        func_004E8758(1);
        func_00138D70(0);
        D_002212CC++;
        if (D_00220A20 == 0) {
            D_002209F1 = func_00463F08() != 0;
        }
        D_002209F0 = D_0021DAA0 >= 10;
    } while (done == 0);
    if (D_0021EE54 == 1) {
        func_00161D00();
        func_0015ADC8();
    }
    if (D_00220A15 == 0) {
        func_00449B28(5, 0);
    }
    if (D_0021EE54 == 1) {
        func_00161D00();
        func_0015ADC8();
    }
    func_004F5428();
    return 1;
}
