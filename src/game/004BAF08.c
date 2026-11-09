#include "common.h"

extern void func_00497980(s32 arg0);
extern s32 func_004BAD90(s32 index);
extern void func_00501498(s32 arg0);
extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern void func_00505C90(s32 arg0);
extern s32 D_0021F198;
extern u8 D_0021F939;
extern u8 D_0021F93A;

u8 D_0021F8E8 = 0;

void func_004BAF08(s32 arg0) {
    s32 saved;
    s32 v;

    saved = func_00505B20();
    func_00505AD8(arg0);
    func_00501498(func_004BAD90(arg0));
    func_00505C90(func_004BAD90(arg0));
    func_00505AD8(saved);
    v = D_0021F8E8;
    if (v == 0) {
        func_00497980(5);
    } else {
        D_0021F8E8 = 0;
    }
    v = D_0021F198;
    if (v == -1) {
        if (D_0021F939 == 0) {
            D_0021F93A = 1;
        }
    }
}
