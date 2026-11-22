#include "common.h"

extern void func_00453630(void *, s32);
extern s32 D_0023FF00[];
extern s32 D_00222558;
extern s32 D_0022255C;
extern s32 D_00222560;
extern s32 D_00222564;
extern u8 D_00275EC0[];

void func_L00_005D3BD8(s32 *arg0) {
    D_0023FF00[40] = *arg0;
    D_00222558 = *arg0;
    *arg0 += 0x20000;
    D_00222560 = -1;
    D_0022255C = 0;
    D_00222564 = 0;
    func_00453630(D_00275EC0, 0x200);
}
