#include "common.h"

extern s32 D_0021DE98;
extern s32 D_003D9E20[];
extern s32 D_00221F28;
extern s32 D_0021EE6C;
extern s32 D_0021EE68;
extern void func_004E84F8(void);

/* Initialize the mode-dependent addresses and continue setup. */
void func_004E8448(void)
{
    s32 value = 0x160000;
    s32 mode;
    D_00221F28 = value;
    mode = D_0021DE98;
    if (mode > 0) {
        if (mode < 20) {
            D_00221F28 = D_003D9E20[mode];
        } else if (mode < 40) {
            D_00221F28 = D_003D9E20[mode - 20];
        } else if (mode < 60) {
            D_00221F28 = 0x120000;
        } else if (mode < 80) {
            D_00221F28 = 0x120000;
        } else {
            D_00221F28 = value;
        }
    }
    D_0021EE6C = 0xF000;
    D_0021EE68 = 0x1E000;
    func_004E84F8();
}
