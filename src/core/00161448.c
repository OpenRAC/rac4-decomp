#include "common.h"

extern s32 func_00161380(void);
s32 func_00152DB8(s32, void *);
void func_001525A8(void *);
s32 D_0021E02C = 0;

/* Probes with a status word; when it is not 1 and D_0021E02C is 1, calls func_00161380, then passes the global's address to func_001525A8. */
s32 func_00161448(void) {
    s32 sp0;

    sp0 = 0;
    if (func_00152DB8(1, &sp0) == 1) {
        return 0;
    }
    if (D_0021E02C == 1) {
        sp0 = func_00161380();
    }
    func_001525A8(&D_0021E02C);
    return sp0;
}
