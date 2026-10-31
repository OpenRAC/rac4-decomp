#include "common.h"

/* Registers the current owner's entry in D_30B7F8 with func_004976C8 using the callbacks, then calls func_00497980 with 0x15 on success or 4 on failure. */
extern s32 func_004976C8(s32 *value_ptr, s32 param_a, s32 mode, void (*before)(void), void (*after)(void), s32 param_b);
extern void func_00497980(s32 arg0);
extern s32 func_00505B20(void);
extern u8 D_30B7F8[];
extern void func_004C33D0(void);
extern void func_004C34D8(void);
extern void func_004C3310(void);

void func_004C37A0(s32 arg0) {
    s32 idx;
    u32 base;

    idx = func_00505B20();
    base = idx * 0x74 + (u32)D_30B7F8;
    if (func_004976C8((s32 *)(base + 0x18), 8, arg0, func_004C33D0, func_004C34D8, (s32)func_004C3310) != 0) {
        func_00497980(0x15);
        return;
    }
    func_00497980(4);
}
