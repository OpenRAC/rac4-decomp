#include "common.h"

extern void *func_L00_005E4298(s32);
extern void func_005CF678(void *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

// Allocate an object with func_L00_005E4298 (id 0x61) and, when that succeeds,
// initialize it with func_005CF678 from the eight integer and three float
// parameters. Returns the object or null.
void *func_L01_005CF8B8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f0, f32 f1, f32 f2) {
    void *ptr = func_L00_005E4298(0x61);
    if (ptr != 0) {
        func_005CF678(ptr, a0, a1, a2, a3, a4, a5, a6, a7, f0, f1, f2);
    }
    return ptr;
}
