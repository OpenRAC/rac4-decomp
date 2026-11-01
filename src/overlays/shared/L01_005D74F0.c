#include "common.h"

/* Wrapper: calls func_005E6028 with a3 = -1, passing a0 to a2 through. */
extern void func_005E6028();

void func_L01_005D74F0(s32 a0, s32 a1, s32 a2) {
    func_005E6028(a0, a1, a2, -1);
}
