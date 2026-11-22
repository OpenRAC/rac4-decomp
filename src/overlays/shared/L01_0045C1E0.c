#include "common.h"

typedef struct T2 { char _p0[0x50]; s32 f50; char _p54[0x9C - 0x54]; s32 f9C; } T2;
typedef struct T1 { char _p0[0xAC]; T2 *fAC; } T1;

extern void func_L01_005ABDE8(void *, f32, f32, f32);
extern void func_00473A88(void *, s32, s32);
extern void func_L01_00591C70(void *, s32);

s32 func_L01_0045C1E0(T1 *arg0, s32 arg1) {
    T2 *p = arg0->fAC;
    switch (arg1) {
    case 0:
        p->f50 |= 0x80;
        break;
    case 1:
        func_L01_005ABDE8(arg0, 10.0f, 18.5f, 22.0f);
        break;
    case 4:
        p->f50 &= ~0x80;
        p->f9C = 0;
        func_L01_00591C70(arg0, 5);
        func_00473A88(arg0, 2, 2);
        break;
    }
    return 1;
}
