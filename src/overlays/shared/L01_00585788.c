#include "common.h"

extern void *func_006C1008(s32);
extern void func_L00_005DA5D8(s32, s32);
extern s32 func_L00_00702608(s32, s32);
extern void func_L01_006C1388(u8 *arg0);
extern void func_L01_006C14F0(u8 *p);
extern s32 D_0021DE10;
s32 D_0021EBD8 = 0;
extern u8 D_1F87F0[];

// Looks up the current slot's entry and, when its flag is clear, resets the entry's two sub-objects.
void func_L01_00585788(void) {
    s32 a = D_0021DE10;
    s32 b = D_0021EBD8;
    s32 flags = D_1F87F0[b * 12 + ((a - 1) % 20) * 0x304 + 8];

    if (((flags >> 2) & 1) == 0) {
        u8 *s = (u8 *)func_006C1008(func_L00_00702608(a, b));

        func_L01_006C1388(s + 0x2C);
        func_L01_006C14F0(s + 0x50);
        func_L00_005DA5D8(0, -1);
    }
}
