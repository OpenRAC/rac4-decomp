#include "common.h"

extern void func_L00_0066CCE8(u8 *, s32);

void func_L01_00474530(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0xAC);
    p[0xE] = 0;
    p[0xF] = 0;
    func_L00_0066CCE8(arg0, 1);
}
