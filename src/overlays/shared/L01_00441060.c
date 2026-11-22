#include "common.h"

extern void func_004706F0(void *);

void func_L01_00441060(void *obj, f32 x) {
    if (x > 0.0f) {
        x = x * 1024.0f * 1.5f;
    } else {
        x = *(f32 *)((u8 *)obj + 0xC);
    }
    func_004706F0(obj);
    *(f32 *)((u8 *)obj + 0xC) = x;
}
