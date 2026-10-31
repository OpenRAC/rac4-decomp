#include "common.h"

extern s32 func_004976C8(s32 *value_ptr, s32 param_a, s32 mode, void (*before)(void), void (*after)(void), s32 param_b);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern s32 func_00505B20(void);
extern u8 D_30A160[];
extern void func_004B8928(void);
extern void func_004B89E0(void);
extern u8 func_004B8908(s32 arg0);

/* Starts the entry at D_30A160 for slot func_00505B20() with mode arg0, and runs func_004E21D8 and func_004E0858 if that succeeds. */
void func_004B8AA8(s32 arg0) {
    u8 *base;

    base = D_30A160 + (func_00505B20() << 4);
    if (func_004976C8((s32 *)(base + 4), 6, arg0, func_004B8928, func_004B89E0, (s32)func_004B8908) != 0) {
        func_004E21D8(0, 0, 0);
        func_004E0858();
    }
}
