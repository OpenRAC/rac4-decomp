#include "common.h"

extern u8 D_002221D8;
extern void func_L00_00688010(void);
extern void func_004493E8(void *, void (*)(void), u32);

// Registers func_L00_00688010 with the subsystem object at D_002221D8, passing ARG0 through.
void func_L00_00687FE0(u32 arg0) {
    func_004493E8(&D_002221D8, func_L00_00688010, arg0);
}
