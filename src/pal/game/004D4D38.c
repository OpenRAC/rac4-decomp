/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/3B3050.c func_003B3910.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

s32 D_0021FC28 = 0;
extern void func_004D49F0(void);
extern void func_004D4958(void);
extern void func_004D4B78(void);
extern void func_004D4A88(void);
extern void func_004D4C10(void);
extern void func_004D4CD0(void);
extern void func_004D48B8(void);
extern void func_004D4818(void);
extern s32 func_004800B0(s32, s32);
void func_004D4D38(void)
{
    switch (D_0021FC28) {
    case 1:
        func_004D49F0();
        break;
    case 2:
        func_004D4958();
        break;
    case 3:
        func_004D4B78();
        break;
    case 7:
        func_004D4A88();
        break;
    case 8:
        func_004D4C10();
        break;
    case 5:
        func_004D4CD0();
        break;
    case 4:
        func_004D48B8();
        break;
    case 6:
        func_004D4818();
        break;
    case 0:
    default:
        func_004800B0(0, 0);
        break;
    }
}
