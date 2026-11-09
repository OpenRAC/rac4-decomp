#include "common.h"

extern s32 func_00505AD8(s32 a);
extern s32 func_00505B20(void);
extern s32 func_00505ED0(u32 id, u32 child, s32 index);
extern s32 func_00506060(u32 id, u32 child);

void func_0049D308(s32 arg0, s32 arg1, s32 arg2) {
    s32 saved;
    s32 child;
    s32 t;

    saved = func_00505B20();
    func_00505AD8(arg0);
    t = (arg1 << 8) + 0x110001;
    child = (arg0 << 12) + t + 1;
    func_00506060((arg0 << 12) + 0x110001, child);
    func_00505ED0(arg2, child, 0);
    func_00505AD8(saved);
}
