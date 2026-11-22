/* cflags: -ffast-math */
#include "common.h"

extern s32 func_L01_005B4FE8(void *, s32, s32);
extern u8 func_004887D8(s32, s32);

typedef struct T2 { char _p0[0x348]; f32 f348; char _p34C[0x614 - 0x34C]; u8 f614; } T2;
typedef struct T1 { char _p0[0xAC]; T2 *fAC; } T1;

void func_L01_0045B1E0(T1 *a) {
    T2 *p = a->fAC;
    func_L01_005B4FE8(a, 1, p->f614 == 0);
    func_L01_005B4FE8(a, 3, p->f614 == 0);
    if (p->f614 != 0) {
        p->f348 = (p->f348 < 15.0f) ? 15.0f : p->f348;
        func_004887D8((s32)a, 0);
    }
}
