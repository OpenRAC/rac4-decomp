#include "common.h"

typedef struct T1 { char _p0[0x69]; u8 f69; } T1;
extern void func_00473A88(void *, s32, s32);

void func_L01_0045A3A0(T1 *arg0, u32 arg1) {
    s32 v = -1;
    switch (arg1) {
    case 0: v = 0x10; break;
    case 2: v = 0x16; break;
    case 1: v = 0x13; break;
    case 3: v = 0x18; break;
    case 4: v = 0x19; break;
    case 5: v = 0x14; break;
    }
    if (v != -1) {
        func_00473A88(arg0, v, (arg0->f69 == 4) ? -1 : 4);
    }
}
