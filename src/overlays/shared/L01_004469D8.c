#include "common.h"

extern void func_L01_00446778(void *, f32, f32);
extern void func_0046BDD0(void *);
extern void func_004706F0(void *);
extern s32 func_00453508(void *);
extern void func_00473A88(void *, s32, s32);

void func_L01_004469D8(void *obj) {
    u8 *p = *(u8 **)((u8 *)obj + 0xAC);
    f32 t;
    f32 c;
    switch (*((u8 *)obj + 0x20)) {
    case 0:
        *(f32 *)((u8 *)obj + 0x70) *= *(f32 *)(p + 0x14);
        func_L01_00446778(obj, *(f32 *)(p + 8), *(f32 *)(p + 0xC));
        t = *(f32 *)p - *(f32 *)(p + 4);
        *(f32 *)p = t;
        *((u8 *)obj + 0x23) = (s32)t;
        c = *(f32 *)((u8 *)obj + 0xC);
        func_004706F0(obj);
        *(f32 *)((u8 *)obj + 0xC) = c;
        if (func_00453508(p + 0x10) != 0) {
            func_00473A88(obj, 1, -1);
        }
        break;
    case 1:
        func_0046BDD0(obj);
        break;
    }
}
