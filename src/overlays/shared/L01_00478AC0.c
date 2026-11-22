#include "common.h"
typedef struct S { char _p0[0xA4]; s32 fA4; s32 fA8; } S;
typedef struct O { char _p0[0x68]; u8 f68; char _p69[0xAC - 0x69]; S *fAC; } O;
extern s32 D_0039D140[][6];
void func_L01_00478AC0(O *arg0) {
    S *s = arg0->fAC;
    if (s->fA4 != -1) {
        arg0->f68 = s->fA4;
        D_0039D140[s->fA8][s->fA4] = 0;
    }
}
