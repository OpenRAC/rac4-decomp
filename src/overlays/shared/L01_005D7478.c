#include "common.h"

/* Tail-free wrapper: calls func_005E5BE0 with a2 = -1, passing a0 and a1 through. */
extern void func_005E5BE0();

void func_L01_005D7478(s32 a0, s32 a1) {
    func_005E5BE0(a0, a1, -1);
}
