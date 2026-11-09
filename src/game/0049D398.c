#include "common.h"

extern void func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern s32 func_00505DD0(u32 id, s32 amount);
extern s32 func_00506060(u32 id, u32 child);

void func_0049D398(s32 arg0, s32 arg1, s32 arg2) {
    s32 base = 0x110001;
    s32 saved;
    s32 a;

    saved = func_00505B20();
    func_00505AD8(arg0);
    a = arg0 << 12;
    func_00506060(arg2, a + ((arg1 << 8) + base) + 1);
    func_00505DD0(a + base, a + ((arg1 << 8) + base) + 1);
    func_00505AD8(saved);
}
