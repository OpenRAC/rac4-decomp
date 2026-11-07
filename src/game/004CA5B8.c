#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x10];
} Type30E9D8;

extern s32 func_00497580(s32 *current, s32 count, s32 (*predicate)(void));
extern s32 func_00497628(s32 *current, s32 count, s32 (*predicate)(void));
extern s32 func_004983E8(s32 arg0);
extern void func_004CA1D0(s32 arg0, s32 arg1);
extern void func_004CA850(void);
extern void func_004CAEC0(s32 arg0);
extern void func_004CAEC8(s32 index);
extern s32 func_004CAF30(s32 arg0);
extern s32 func_004CAF90(void);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);

s32 D_0021FA28 = -1;
s32 D_0021FA2C = 1;
extern u8 D_0021EE18;
extern s32 D_00171948[][8];
extern Type30E9D8 D_0030E9D8;

void func_004CA5B8(void) {
    s32 result = 0;
    s32 flag;
    s32 mode;

    switch (func_004983E8(6)) {
    case 2:
    case 13:
        func_004CA850();
        break;
    case 1:
        flag = D_0021FA28;
        if (flag == 1) {
            if (func_004CAF30(D_0030E9D8.unk4) != 0) {
                func_004E21D8(14, 0, 0);
                func_004CA1D0(14, 0);
                break;
            }
            if (D_0021EE18 != 0) {
                D_0021FA2C = flag;
                func_004CA1D0(2, 0);
            } else {
                mode = 13;
                goto set_mode;
            }
        } else if (D_0021EE18 != 0) {
            D_0021FA2C = D_00171948[D_0030E9D8.unk4][19];
            func_004CA1D0(2, 0);
        } else {
            mode = 23;
        set_mode:
            func_004CA1D0(mode, 0);
        }
        func_004E21D8(7, 0, 0);
        break;
    case 5:
        func_004CAEC0(D_0030E9D8.unk4);
        result = func_00497580(&D_0030E9D8.unk4, 4, func_004CAF90);
        func_004CAEC8(D_0030E9D8.unk4);
        break;
    case 6:
        func_004CAEC0(D_0030E9D8.unk4);
        result = func_00497628(&D_0030E9D8.unk4, 4, func_004CAF90);
        func_004CAEC8(D_0030E9D8.unk4);
        break;
    }
    if (result != 0) {
        func_004E21D8(0, 0, 0);
        func_004E0858();
    }
}
