#include "common.h"

extern s32 D_357D68[];
u8 D_00221918 = 0;

// Clear the table at D_357D68 once, then set the flag at D_00221918.
void func_L01_0046EBF0(void) {
    s32 *p;
    s32 i;
    s32 j;

    if (D_00221918 == 0) {
        D_357D68[138] = 5;
        D_357D68[137] = 0;
        D_357D68[136] = 0;
        p = D_357D68;
        for (i = 0x3F; i >= 0; i--) {
            p[0] = 0;
            p[64] = 0;
            p++;
        }
        for (j = 7; j >= 0; j--) {
            D_357D68[128 + j] = 0;
        }
        D_00221918 = 1;
    }
}
