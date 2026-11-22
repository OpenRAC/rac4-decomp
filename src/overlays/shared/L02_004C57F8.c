#include "common.h"
extern void func_00476158(void *, f32, f32, f32, f32);
extern f32 D_0039AE70[];
s32 func_L02_004C57F8(s32 arg0, u8 *arg1) {
    func_00476158(arg1 + 0x1C8, 0.0f, 0.0014544411f, 0.0014544411f, 0.14544411f);
    D_0039AE70[12] = 0.0f;
    D_0039AE70[13] = 0.0f;
    D_0039AE70[14] = 0.0f;
    D_0039AE70[15] = 0.0f;
    D_0039AE70[16] = 0.0f;
    D_0039AE70[17] = 0.0f;
    *(f32 *)(arg1 + 0x1F0) = 0.0f;
    *(f32 *)(arg1 + 0x1F4) = 0.0f;
    return 0;
}
