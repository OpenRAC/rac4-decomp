#include "common.h"

extern s32 func_L00_006688C8(s32);
extern void func_L00_00679408(void);
extern s32 *D_00222D68;
extern s32 D_00222D70;
extern s32 *D_00222EE0;
extern s32 D_0021DA30;

void func_L00_00666CE8(void) {
    s32 *t;
    s32 n;

    t = D_00222EE0;
    D_00222EE0 = t + 4;
    D_00222D68[0] = 0x20000000;
    D_00222D68[1] = (s32)D_00222EE0;
    D_00222D68[2] = 0;
    D_00222D68[3] = 0;
    n = func_L00_006688C8(D_0021DA30);
    func_L00_00679408();
    if (D_00222D70 < n) {
        D_00222D70 = n;
    }
    D_00222EE0[0] = 0x20000000;
    D_00222EE0[1] = (s32)(D_00222D68 + 4);
    D_00222EE0[2] = 0;
    D_00222EE0[3] = 0;
    D_00222EE0 += 4;
    t[0] = 0x20000000;
    t[1] = (s32)D_00222EE0;
    t[2] = 0;
    t[3] = 0;
}
