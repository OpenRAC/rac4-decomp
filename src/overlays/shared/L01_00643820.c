#include "common.h"

extern u8 D_00222A98;
extern void func_004F5E48(void);
extern void func_004493E8(void *, void (*)(void), u32);

// Registers func_004F5E48 with the subsystem object at D_00222A98, passing ARG0 through.
void func_L01_00643820(u32 arg0) {
    func_004493E8(&D_00222A98, func_004F5E48, arg0);
}
