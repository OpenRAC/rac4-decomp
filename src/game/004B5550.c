#include "common.h"

extern void *func_004B5478(void);
extern void func_005014B0(s32 *a0);
extern s32 func_00505AD8();
extern s32 func_00505B20();
extern u8 D_221770;

// Decrements the byte counter D_221770; when it reaches zero, runs func_004B5478's object through func_005014B0 under mode 4.
void func_004B5550(void) {
    s32 saved;

    if (--D_221770 == 0) {
        saved = func_00505B20();
        func_00505AD8(4);
        func_005014B0(func_004B5478());
        func_00505AD8(saved);
    }
}
