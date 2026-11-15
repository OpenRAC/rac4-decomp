#include "common.h"

typedef struct { char _p[0x158]; s32 f158; void (*f15C)(s32, s32, s32); s32 f160; s32 f164; s32 f168; s32 f16C; } E;
typedef struct { char _p[0x14]; s32 f14; char _p18[4]; } F;
extern E D_00308B80[];
extern F D_00308460[];
s32 func_00505B20(void);
void func_00504F68(s32, s32);
void func_00496B28(E *, s32);
void func_004AB7B8(s32 j) {
    s32 i = func_00505B20();
    if (D_00308B80[i].f15C != 0) {
        if (j < 0) {
            D_00308B80[i].f15C(i, 0, D_00308B80[i].f168);
        } else {
            D_00308B80[i].f15C(i, D_00308460[j].f14, D_00308B80[i].f168);
        }
    }
    D_00308B80[i].f158 = -1;
    D_00308B80[i].f15C = 0;
    D_00308B80[i].f160 = 0;
    D_00308B80[i].f168 = 0;
    func_00504F68(0x7000B, 0);
    func_00504F68(0x7000C, 0);
    func_00496B28(&D_00308B80[i], 7);
}
