/* cflags:  -Wuninitialized -Wa,-G0 */
#include "pal/decomp.h"
typedef int solver_s128 __attribute__((mode(TI)));
typedef unsigned int solver_u128 __attribute__((mode(TI)));
typedef solver_s128 s128; typedef solver_u128 u128;

s64 func_L01_005DAD78(s32 arg0, s32 arg1);
float func_L01_005DAE60(s32 arg0, float a, float b, s32 arg1, float c);
int D_00222714 = 0;
extern u32 D_00294140[];
void func_L08_004CE5F0(void *arg0) {
    s32 temp_4;
    s32 var_2;
    void *temp_17;

    temp_17 = M2C_FIELD(arg0, void **, 0xAC);
    func_L01_005DAD78(M2C_FIELD(temp_17, s32 *, 0x14), 0U);
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(D_00294140[M2C_FIELD(temp_17, s32 *, 0x14)], s128 *, 0x10);
    M2C_FIELD(temp_17, s32 *, 0x24) = (s32) (((func_L01_005DAE60(M2C_FIELD(temp_17, s32 *, 0x14), 0.0f, 0.0f, 1, 100000.0f) * 2.4f * 5.0f) + 2.0f) / 6.0f);
    temp_4 = M2C_FIELD(temp_17, s32 *, 8);
    if (temp_4 != -1) {
        var_2 = D_00222714 + ((u32) temp_4 << 8);
    } else {
        var_2 = 0;
    }
    M2C_FIELD(temp_17, s32 *, 0x1C) = var_2;
}
