#include "common.h"

/* Mark the selected slot and optionally update either active index. */
typedef struct {
    u8 p0[0x1C];
    u8 f1C[8];
    u8 p24[2];
    u8 f26, f27;
} Type1;
extern Type1 D_00171B80;
void func_0047D448(u32 i, u32 mask)
{
    if (i < 8) {
        D_00171B80.f1C[i] = 1;
        if (mask & 1)
            D_00171B80.f26 = i;
        if (mask & 2)
            D_00171B80.f27 = i;
    }
}
