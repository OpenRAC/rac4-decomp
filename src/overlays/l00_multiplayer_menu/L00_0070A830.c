#include "common.h"

extern void func_L00_0070A010(s32, s32);
extern s32 D_003F3D58[];
extern s8 D_00220A5D;
extern s8 D_00220A5E;
s8 D_00220A5F = 0;

/* Calls 0070A010 on entries 1 to 3 of D_003F3D58 with -1, clearing a flag byte after each of the first three calls. */
void func_L00_0070A830(void) {
    s32 *p;

    p = D_003F3D58;
    func_L00_0070A010(p[1], -1);
    D_00220A5D = 0;
    func_L00_0070A010(p[2], -1);
    D_00220A5E = 0;
    func_L00_0070A010(p[3], -1);
    D_00220A5F = 0;
}
