#include "common.h"

typedef struct {
    u8 pad0[0x10];
    u8 vec[0x60];
    f32 f70;
} S_4DC928;
s32 D_00222208 = 0;
s32 D_0022220C = 0;
s32 D_00222210 = 0;
s32 D_00222214 = 0;
extern s32 func_00472590(s32, s32);
extern f32 func_00472690(void);
extern void func_L05_004DCA00(u8 *, int, f32, int, int, f32, f32, int, S_4DC928 *);

/* from rac2-decomp's func_L16_003E70E0 */
void func_L05_004DC928(S_4DC928 *a0) {
    func_L05_004DCA00(a0->vec, D_00222210, a0->f70,
                      func_00472590(0x5F, 0x6F), D_00222208, func_00472690(),
                      1.0f, 2, a0);
    {
        f32 half = a0->f70 * 0.5f;
        func_L05_004DCA00(a0->vec, D_00222214, half,
                          func_00472590(0x6F, 0x7F), D_0022220C,
                          func_00472690(), 1.0f, 2, a0);
    }
}
