#include "common.h"

extern s32 func_004976C8(s32 *value_ptr, s32 param_a, s32 mode, void (*before)(void), void (*after)(void), s32 param_b);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern s32 func_00505B20(void);
extern u8 D_30A490[];
extern void func_004BA620(void);
extern void func_004BA6D8(void);
extern u8 func_004BA600(s32 arg0);

// Calls func_004976C8 on the entry for the current owner (func_00505B20); if it returns nonzero, calls func_004E21D8 and func_004E0858.
void func_004BA7A0(s32 arg0) {
    s32 index = func_00505B20();
    u8 *entry = (u8 *)D_30A490 + index * 0x14;

    if (func_004976C8((s32 *)(entry + 4), 8, arg0, func_004BA620, func_004BA6D8, (s32)func_004BA600) != 0) {
        func_004E21D8(0, 0, 0);
        func_004E0858();
    }
}
