/* cflags: -ffast-math -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))


void func_00513988(void *arg0, f32 fparg0) {
    f32 temp_f12;
    f32 sum;
    void *temp_2;
    void *temp_3;

    if (M2C_FIELD(arg0, u8 *, 0x266D) == 0) {
        goto block_5;
    }
    if (fparg0 <= 0.0f) {
        goto block_5;
    }
    temp_3 = M2C_FIELD(arg0, void **, 0x2F28);
    M2C_FIELD(arg0, s32 *, 0x2ED8) = 0x12C;
    sum = M2C_FIELD(arg0, f32 *, 0x2E20) + fparg0;
    temp_f12 = sum > M2C_FIELD(arg0, f32 *, 0x2F24) ? M2C_FIELD(arg0, f32 *, 0x2F24) : sum;
    M2C_FIELD(arg0, f32 *, 0x2E20) = temp_f12;
    if (temp_3 == NULL) {
        goto block_5;
    }
    temp_2 = M2C_FIELD(temp_3, void **, 4);
    if (temp_2 == NULL) {
        goto block_5;
    }
    M2C_FIELD(temp_2, f32 *, 0x44) = temp_f12;
block_5:
    return;
}
