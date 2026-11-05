#include "common.h"

extern u8 D_221218;
extern void func_004F5E48(void);
extern void func_004493E8(void *, void (*)(void), u32);

// Registers func_004F5E48 with the subsystem object at D_221218, passing ARG0 through.
void func_004F5E18(u32 arg0) {
    func_004493E8(&D_221218, func_004F5E48, arg0);
}
