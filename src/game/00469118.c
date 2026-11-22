#include "common.h"

typedef struct {
    u8 pad0[0x1B0];
    s32 f1B0;
    u8 pad1[0x10];
    s32 f1C4;
    u8 pad2[4];
    s32 f1CC;
    s32 f1D0;
    u8 pad3[8];
    u8 *f1DC;
    u8 pad4[4];
    s32 f1E4;
} S;
extern S D_00171948;
extern s32 D_0021DA40;
extern u8 D_001FB530[];
extern u8 D_003D80C0[];
extern s32 func_00138290(void *);
extern void func_00155A98(void *);
extern s32 func_00468C78(void *, s32, void *);

s32 func_00469118(void)
{
    func_00138290(&D_0021DA40);
    func_00155A98(&D_0021DA40);
    if (D_00171948.f1B0 == -1) {
        return 0;
    }
    if (D_00171948.f1E4 != 0 && D_00171948.f1C4 < 3 && D_00171948.f1CC < 0) {
        D_00171948.f1DC = D_001FB530;
        func_00468C78(D_001FB530, 0, D_003D80C0);
        if (D_00171948.f1CC < 0) {
            D_00171948.f1CC = 0x22;
            D_00171948.f1D0 = D_00171948.f1B0;
        }
    }
    return D_00171948.f1CC == 0x22;
}
