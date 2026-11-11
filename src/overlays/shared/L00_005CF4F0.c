#include "common.h"
/* Ported from rac3-decomp's func_L01_0042AEC0 (src/levels/shared/L01_0042AE30.c, GPL-3.0), the same code in both games. */

typedef struct {
    s32 cur;
    u8 pad4[8];
    s32 count;
    u8 pad10[16];
    u8 entries[1][16];
} Struct_001F3FC0;
extern Struct_001F3FC0 D_00247700;
extern s32 func_L00_005BD188(s32, void *, void *);
s32 func_L00_005CF4F0(s32 a0)
{
    s32 i;
    for (i = D_00247700.count - 1; i >= 0; i--) {
        if (func_L00_005BD188(a0, D_00247700.entries[i], D_00247700.entries[i + 2])) {
            return i + 1;
        }
    }
    return 0;
}
