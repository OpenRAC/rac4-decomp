/* cflags:  -Wuninitialized */
#include "common.h"
#define M2C_FIELD(base, kind, offset) (*(kind)((u8 *)(base) + (offset)))

float func_00472EB8(float, float);
void func_L01_003F2610(void *, f32);             /* extern */

void func_L01_003F3758(void *arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xAC), f32 *, 0x2C) > 2.0f) {
        func_L01_003F2610(arg0, func_00472EB8(0.3f, 0.5f));
    }
}
