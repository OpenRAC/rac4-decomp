#include "common.h"

typedef struct { char _p0[0x15AC]; s32 a[16]; s32 n; } Type1;
extern Type1 D_00172160;
void func_0015F3F0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_00172160.a[i] = -1;
    }
    D_00172160.n = 0;
}
