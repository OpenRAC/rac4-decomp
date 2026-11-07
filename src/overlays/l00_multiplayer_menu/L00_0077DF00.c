#include "common.h"

extern u8 D_004C1FB8[];
extern void func_01EF03CC(u8 *);

void func_L00_0077DF00(u8 *arg0) {
    *(u32 *)(arg0 + 0x1041C) = (u32)D_004C1FB8;
    func_01EF03CC(arg0);
}
