#include "common.h"

extern void func_005BCAE0(void *p, s32 v, s32 n);
extern s32 D_00244F00[];
extern s32 D_00222380;

// Clears the 0x180-byte table at 0x23C030 and zeroes the counter at 0x222230.
void func_L00_005CB580(void) {
    func_005BCAE0(D_00244F00, 0, 0x180);
    D_00222380 = 0;
}
