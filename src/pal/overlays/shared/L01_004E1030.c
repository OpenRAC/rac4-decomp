#include "common.h"

s32 D_002223C0 = 0;
s32 D_002223C4 = 0;
s32 D_002223F8 = 0;
s32 D_002223FC = 0;
f32 D_00222400 = 0;
f32 D_00222404 = 0;
extern s32 func_00472E70(s32, s32);
extern f32 func_00472F70(void);
extern void func_L01_004E1240(u8 *, int, f32, int, int, f32, f32, int, u8 *);

/* PAL: from rac2-decomp's func_L12_004081F8 */
void func_L01_004E1030(u8 *a0) {
    func_L01_004E1240(a0 + 0x10, D_002223C0, D_00222400 * *(f32 *)(a0 + 0x70),
                        func_00472E70(0x5F, 0x6F), D_002223F8, func_00472F70(),
                        1.0f, 2, a0);
    {
        f32 size = D_00222400 * *(f32 *)(a0 + 0x70) * D_00222404;
        func_L01_004E1240(a0 + 0x10, D_002223C4, size,
                            func_00472E70(0x6F, 0x7F), D_002223FC,
                            func_00472F70(), 1.0f, 2, a0);
    }
}
