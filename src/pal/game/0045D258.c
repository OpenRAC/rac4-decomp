#include "common.h"

extern s32 D_0021DE98;
extern s32 D_0021DAF8;
extern s32 D_0021DF04;
extern s32 D_002213E0;
extern u8 D_001719C8[];
extern void func_004FFD10(void);
extern void func_0045D250(s32 *);
extern void func_00466640(s32);
extern void func_0045D368(void);
extern void func_00469B80(s32, s32);

s32 D_0021EE3C = 0;
u32 D_0021EE54 = 0;

void func_0045D258(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *pointer;
    s32 state;
    s32 value;

    func_004FFD10();
    func_0045D250(&arg0);
    value = arg0;
    state = D_0021DE98;
    D_0021EE3C = 1;
    D_0021DAF8 = state;
    D_0021DF04 = arg2;
    D_002213E0 = value;
    if (value == -1) {
        pointer = D_001719C8;
        if (*(s32 *)(pointer + 0x1E4) != 0) {
            *(s32 *)(pointer + 0x1E4) = 0;
        }
        if (*(s16 *)(pointer + 0x18) >= 0) {
            *(s16 *)(pointer + 0x18) = value;
        }
        func_00466640(7);
    }
    if (D_0021EE54 == 0 && arg1 != 0) {
        func_0045D368();
        func_00469B80(0, D_002213E0);
    }
}

/* The callback helpers share the mode and callback-count storage above. */

extern s32 D_003288D0[];
extern s32 D_00328910[];
extern s32 D_00328890[];
extern void func_00159130(void);
extern void func_00159138(void);
extern void func_004F3630(s32, s32 *);
extern void func_00158790(s32, s32, s32, s32, s32, s32, void (*)(s32, s32 *), s32 *);
extern s32 func_00157FA8(void);

s32 D_00220A00 = 0;

/* Initialize an indexed callback slot. */
void func_004F3640(s32 arg0)
{
    s32 index;
    s32 *slot;
    if (arg0 < 0 || arg0 >= D_00220A00) {
        return;
    }
    index = D_003288D0[arg0];
    slot = &D_00328910[index];
    *slot = -1;
    func_00159130();
    func_00158790(D_00328890[index], 0, 0x400, 0, 0, 0, func_004F3630, slot);
    func_00159138();
    func_00157FA8();
}


extern s32 D_00328890[];
extern void func_00159130(void);
extern void func_00159138(void);
extern void func_001585A8(s32);
extern s32 func_00157FA8(void);
extern void func_00161D00(void);
extern void func_0015ADC8(void);
extern void func_00158578(void);


/* Run both callback loops. */
void func_004F36E8(void)
{
    u32 i;
    s32 one;
    func_00159130();
    for (i = 0; i < D_00220A00; i++) {
        func_001585A8(D_00328890[i]);
    }
    func_00159138();
    one = 1;
    while (func_00157FA8() != 0) {
        if (D_0021EE54 == one) {
            func_00161D00();
            func_0015ADC8();
        }
    }
    func_00158578();
}
