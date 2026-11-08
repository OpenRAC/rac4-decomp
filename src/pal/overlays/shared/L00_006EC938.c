#include "common.h"

extern void func_00453E20(void *, s32, s32);
extern void *func_L00_006EF740(u8 *p);
extern u8 D_004B5A50[];

/* PAL: from rac3-decomp's func_L39_0065F468, constants adapted */
void func_L00_006EC938(u8 *p) {
    func_00453E20(p, 0, 0x31f0);
    func_L00_006EF740(p);
    *(u8 **)(p + 0x14) = D_004B5A50;
    *(u8 *)(p + 0x266d) = 1;
    *(u8 *)(p + 0x31cf) = 5;
}
