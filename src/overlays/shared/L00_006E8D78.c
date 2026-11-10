#include "common.h"

extern void func_00453608(void *, s32, s32);
extern void *func_L00_006EBB80(u8 *p);
extern u8 D_004B5A10[];

void func_L00_006E8D78(u8 *p) {
    func_00453608(p, 0, 0x31f0);
    func_L00_006EBB80(p);
    *(u8 **)(p + 0x14) = D_004B5A10;
    *(u8 *)(p + 0x266d) = 1;
    *(u8 *)(p + 0x31cf) = 5;
}
