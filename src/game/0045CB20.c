#include "common.h"

s32 D_0021EDBC = 0;

// Checks if D_0021EDBC is non-zero
s32 func_0045CB20(void) {
    return D_0021EDBC != 0;
}

extern s32 D_0021DE10;
extern s32 D_0021DA78;
extern s32 D_0021DE7C;
extern s32 D_002212E0;
extern u8 D_00171948[];
extern void func_004FECA0(void);
extern void func_0045CA58(s32 *);
extern void func_00465DF8(s32);
extern void func_0045CB70(void);
extern void func_004692C8(s32, s32);

u32 D_0021EDD4 = 0;

void func_0045CA60(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *pointer;
    s32 state;
    s32 value;

    func_004FECA0();
    func_0045CA58(&arg0);
    value = arg0;
    state = D_0021DE10;
    D_0021EDBC = 1;
    D_0021DA78 = state;
    D_0021DE7C = arg2;
    D_002212E0 = value;
    if (value == -1) {
        pointer = D_00171948;
        if (*(s32 *)(pointer + 0x1E4) != 0) {
            *(s32 *)(pointer + 0x1E4) = 0;
        }
        if (*(s16 *)(pointer + 0x18) >= 0) {
            *(s16 *)(pointer + 0x18) = value;
        }
        func_00465DF8(7);
    }
    if (D_0021EDD4 == 0 && arg1 != 0) {
        func_0045CB70();
        func_004692C8(0, D_002212E0);
    }
}

/* The callback helpers share the mode and callback-count storage above. */

extern s32 D_003288D0[];
extern s32 D_00328910[];
extern s32 D_00328890[];
extern void func_00159120(void);
extern void func_00159128(void);
extern void func_004F25C8(s32, s32 *);
extern void func_00158780(s32, s32, s32, s32, s32, s32, void (*)(s32, s32 *), s32 *);
extern s32 func_00157F98(void);

s32 D_00220960 = 0;

/* Initialize an indexed callback slot. */
void func_004F25D8(s32 arg0)
{
    s32 index;
    s32 *slot;
    if (arg0 < 0 || arg0 >= D_00220960) {
        return;
    }
    index = D_003288D0[arg0];
    slot = &D_00328910[index];
    *slot = -1;
    func_00159120();
    func_00158780(D_00328890[index], 0, 0x400, 0, 0, 0, func_004F25C8, slot);
    func_00159128();
    func_00157F98();
}


extern s32 D_00328890[];
extern void func_00159120(void);
extern void func_00159128(void);
extern void func_00158598(s32);
extern s32 func_00157F98(void);
extern void func_00161CF0(void);
extern void func_0015ADA8(void);
extern void func_00158568(void);


/* Run both callback loops. */
void func_004F2680(void)
{
    u32 i;
    s32 one;
    func_00159120();
    for (i = 0; i < D_00220960; i++) {
        func_00158598(D_00328890[i]);
    }
    func_00159128();
    one = 1;
    while (func_00157F98() != 0) {
        if (D_0021EDD4 == one) {
            func_00161CF0();
            func_0015ADA8();
        }
    }
    func_00158568();
}
