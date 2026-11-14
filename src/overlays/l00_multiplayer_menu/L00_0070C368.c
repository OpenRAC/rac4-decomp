#include "common.h"

extern void func_L00_0070CE18(void *);
extern int D_00220AE0;
extern s8 D_003F3F78[];
u8 D_00220AD2 = 0;

/* Points arg0 at D_00220AE0, clears D_003F3F78's 20-byte entries once, then calls func_L00_0070CE18. */
int *func_L00_0070C368(int *arg0) {
    s32 n;
    s8 *p;

    arg0[0x118] = (int)&D_00220AE0;
    if (D_00220AD2 == 0) {
        n = 0xE;
        p = D_003F3F78;
        p += 0x15;
        do {
            *p = 0;
            n--;
            p += 0x14;
        } while (n >= 0);
        D_00220AD2 = 1;
    }
    func_L00_0070CE18(arg0);
    return arg0;
}
