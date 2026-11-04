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
