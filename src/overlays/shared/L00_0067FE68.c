#include "common.h"

extern u8 *D_00222454;
extern u8 *D_00222470;
extern u8 *D_00335AE8[];

// Collect up to 16 entries (stride 0x100) whose s16 at 0xBC is 0x135F; zero the rest.
void func_L00_0067FE68(void) {
    u8 *p;
    s32 i = 0;
    for (p = D_00222454; p <= D_00222470; p += 0x100) {
        if (*(s16 *)(p + 0xBC) == 0x135F) {
            D_00335AE8[i++] = p;
            if (i >= 16) break;
        }
    }
    for (; i < 16; i++) D_00335AE8[i] = 0;
}
