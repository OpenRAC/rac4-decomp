#include "common.h"

extern u8 D_00222A9C;
extern void func_L01_00416DF8(void);
extern void func_004493E8(void *, void (*)(void), u32);

// Registers func_L01_00416DF8 with the subsystem object at D_00222A9C, passing ARG0 through.
void func_L01_00416DC8(u32 arg0) {
    func_004493E8(&D_00222A9C, func_L01_00416DF8, arg0);
}
