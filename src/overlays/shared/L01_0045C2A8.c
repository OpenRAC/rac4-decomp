#include "common.h"

typedef struct T2 { char _p0[0x60C]; s16 f60C; } T2;
typedef struct T1 { char _p0[0xAC]; T2 *fAC; } T1;

extern void func_L01_0045A518(void *);
extern void func_00481100(void *, s32, s32);
extern void func_00473A88(void *, s32, s32);
extern void func_00480FB8(void *, s32, s32, s32, s32, s32, f32);

s32 func_L01_0045C2A8(T1 *arg0, s32 arg1) {
    T2 *p = arg0->fAC;
    switch (arg1) {
    case 2:
        func_L01_0045A518(arg0);
        p->f60C++;
        if (p->f60C >= 3) {
            func_00481100(arg0, 0xC, 0);
        }
        break;
    case 3:
        break;
    case 4:
        func_00473A88(arg0, 0x12, -1);
        func_00480FB8(arg0, 3, 0, 0, 0, 0, 0.0f);
        break;
    }
    return 1;
}
