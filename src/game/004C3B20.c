#include "common.h"

extern s32 func_004976C8(s32 *value_ptr, s32 param_a, s32 mode, void (*before)(void), void (*after)(void), s32 param_b);
extern void func_00497980(s32 arg0);
extern s32 func_00505B20(void);
extern void func_004C3988(void);
extern void func_004C3A08(void);
extern void func_004C38E8(void);
extern u8 D_30B7F8[];

// Register the owner's entry (0x74 bytes each in D_30B7F8, its field at 0x14) with the callbacks func_004C3988, func_004C3A08 and func_004C38E8, then run func_00497980 (0x15).
void func_004C3B20(s32 arg0) {
    s32 idx;
    u8 *entry;

    idx = func_00505B20();
    entry = (u8 *)((u32)D_30B7F8 + idx * 0x74);
    func_004976C8((s32 *)(entry + 0x14), 9, arg0, func_004C3988, func_004C3A08, (s32)func_004C38E8);
    func_00497980(0x15);
}
