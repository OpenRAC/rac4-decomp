#include "common.h"

typedef struct {
    char _p0[0x8];
    f32 f8;
    char _pC[0x1C];
    s32 f28;
    u8 f2C;
} Type1;

extern Type1 D_00331880;

void func_L01_005F6C60(f32 arg0) {
    if (D_00331880.f8 != arg0) {
        D_00331880.f28 = 0x1E;
        D_00331880.f8 = arg0;
        D_00331880.f2C = 1;
    }
}
