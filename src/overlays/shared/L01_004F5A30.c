#include "common.h"
extern void func_L01_00593D50(void *, f32, f32, f32);
void func_L01_004F5A30(u8 *arg0, u8 *arg1) {
    s32 i;
    f32 *pf;
    void **po;
    if (*(f32 *)(arg1 + 0x14) > 0.0f) {
        func_L01_00593D50(*(void **)(arg0 + 0xB8), 32.0f, *(f32 *)(arg1 + 0x14), 2.0f);
        func_L01_00593D50(arg0, 32.0f, *(f32 *)(arg1 + 0x14), 2.0f);
    }
    pf = (f32 *)(arg1 + 0x2B4);
    po = (void **)(arg1 + 0xD0);
    for (i = 3; i >= 0; i--) {
        if (*po != 0 && *pf > 0.0f) {
            func_L01_00593D50(*po, 32.0f, *pf, 2.0f);
        }
        po++;
        pf++;
    }
}
