#include "common.h"

typedef struct { u8 p0[0x84]; s16 n; u8 p1[0x1F0 - 0x86]; void *slot[1]; } S_B7288;
extern S_B7288 D_00237000;
extern u32 D_002213F4;
extern u32 D_0022140C;

/* from rac3-decomp's func_003BE308 */
void func_004F5530(void (*cb)(void *)) {
    u32 p;
    s32 i;
    for (p = D_002213F4; p != D_0022140C; p += 0x100) {
        cb((void *)p);
    }
    for (i = 0; i < D_00237000.n; i++) {
        if (D_00237000.slot[i] != 0) {
            cb(D_00237000.slot[i]);
        }
    }
}
