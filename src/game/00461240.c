#include "common.h"

extern void func_00453630(void *, s32);
extern void func_004612B8();
extern u8 D_23F880[];
extern u8 D_23F980[];

// Clears two table slots of size 0x20 and 0x30, indexed by arg0 when it is below 8.
void func_00461240(u32 arg0) {
    if (arg0 < 8U) {
        func_004612B8();
        func_00453630((void *)((u8 *)D_23F880 + (arg0 << 5)), 0x20);
        func_00453630((void *)((u8 *)D_23F980 + arg0 * 0x30), 0x30);
    }
}
