#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern s32 func_L00_005E60A0(s32);
extern void func_L00_005E76C8(void *object, s32 a1, s32 a2, s32 a3, f32 f);
extern u8 *func_L01_00588BC0(s32);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern void func_L01_005A8A28(u8 *obj);

// Find the object for id 0x242C or 0x2473, store the 128-bit argument and the copied slots, and return it (0 when neither exists).
u8 *func_L05_00488978(u128 arg0) {
    u8 *obj;
    u8 *state;
    u8 *dst;
    u8 *src;
    s32 i;

    obj = func_L01_00588BC0(0x242C);
    if (obj != 0 || (obj = func_L01_00588BC0(0x2473), obj != 0)) {
        state = *(u8 **)(obj + 0xAC);
        func_L01_005A8A28(obj);
        *(s32 *)(state + 0x2A8) = 0;
        *(u128 *)(obj + 0x10) = arg0;
        *(s32 *)(state + 0x2AC) = 0;
        *(s32 *)(state + 0x2BC) = 0;
        func_L00_005E76C8(obj, 1, 0, 0, (f32) func_L00_005E60A0(*(u8 *)(*(u8 **)(*(u8 **)(obj + 0x24) + 0x4C) + 0x10) - 1));
        src = obj + 0xC0;
        dst = state;
        i = 4;
        do {
            i -= 1;
            *(u128 *)(dst + 0x2D0) = *(u128 *)(obj + 0x10);
            *(u128 *)(dst + 0x320) = *(u128 *)(src + 0x10);
            dst += 0x10;
        } while (i >= 0);
        func_L01_00591BD8(obj, 1, -1);
    }
    return obj;
}
