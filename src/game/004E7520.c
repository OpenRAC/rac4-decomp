#include "common.h"

extern s32 D_0021DE10;
extern s32 D_003D9DE0[];
extern s32 D_00221E28;
extern s32 D_0021EDEC;
extern s32 D_0021EDE8;
extern void func_004E75D0(void);

/* Initialize the mode-dependent addresses and continue setup. */
void func_004E7520(void)
{
    s32 value = 0x160000;
    s32 mode;
    D_00221E28 = value;
    mode = D_0021DE10;
    if (mode > 0) {
        if (mode < 20) {
            D_00221E28 = D_003D9DE0[mode];
        } else if (mode < 40) {
            D_00221E28 = D_003D9DE0[mode - 20];
        } else if (mode < 60) {
            D_00221E28 = 0x120000;
        } else if (mode < 80) {
            D_00221E28 = 0x120000;
        } else {
            D_00221E28 = value;
        }
    }
    D_0021EDEC = 0xF000;
    D_0021EDE8 = 0x1E000;
    func_004E75D0();
}
