#include "common.h"

/* Tail-free wrapper: calls func_00591BD8 with a2 = -1, passing a0 and a1 through. */
extern void func_00591BD8();

void func_L01_004C8AC8(s32 a0, s32 a1) {
    func_00591BD8(a0, a1, -1);
}
