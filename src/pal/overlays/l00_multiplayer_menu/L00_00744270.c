#include "common.h"

s32 D_L00_0022126C = 0;
u8 D_L00_00221270 = 0;
u8 D_L00_00221271 = 0;

extern u8 *D_L00_00221274;
extern u8 D_L00_004EF0C8[];
extern s32 func_00454C18(void);

/* Update the marker flags and publish the table after them. */
void func_L00_00744270(void)
{
    if (D_L00_004EF0C8[0] == 0xFF) {
        D_L00_004EF0C8[1] = 0xFE;
        D_L00_00221270 = 1;
        D_L00_00221271 = 0;
    } else if (D_L00_004EF0C8[1] == 0xFF) {
        D_L00_004EF0C8[0] = 0xFE;
        D_L00_00221270 = 1;
        D_L00_00221271 = 1;
    }
    D_L00_00221274 = &D_L00_004EF0C8[2];
    D_L00_0022126C = func_00454C18();
}
