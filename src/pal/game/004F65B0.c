#include "common.h"

typedef struct { u8 p0[0x84]; s16 n; u8 p1[0x16A]; void *slot[1]; } S_4F65B0;
extern S_4F65B0 D_00237100;
extern u32 D_002214F4;
extern u32 D_0022150C;

/* PAL: from rac3-decomp's func_003BE308 */
void func_004F65B0(void (*cb)(u32)) {
    u32 p;
    s32 i;
    for (p = D_002214F4; p != D_0022150C; p += 0x100) {
        cb(p);
    }
    for (i = 0; i < D_00237100.n; i++) {
        if (D_00237100.slot[i] != 0) {
            ((void (*)(void *))cb)(D_00237100.slot[i]);
        }
    }
}
