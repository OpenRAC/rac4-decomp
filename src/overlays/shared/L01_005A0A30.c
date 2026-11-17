#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern u8 *func_L00_005DD000(s32, s32);
extern void func_L00_005E4118(void *);

// Spawn a copy of the object scaled by its class size; return it or 0.
u8 *func_L01_005A0A30(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *obj = func_L00_005DD000(arg1, 0x80);

    if (obj != 0) {
        u16 id = *(u16 *)(arg0 + 0x32);
        obj[0x31] = 1;
        *(u16 *)(obj + 0x32) = id;
        *(f32 *)(obj + 0x70) = *(f32 *)(obj + 0x70) *
            (*(f32 *)(arg0 + 0x70) / *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24));
        *(u128 *)(obj + 0x10) = *(u128 *)(arg0 + 0x10);
        *(u128 *)(obj + 0xF0) = *(u128 *)(arg0 + 0xF0);
        *(s64 *)(obj + 0x38) = *(s64 *)(arg0 + 0x38);
        obj[0x30] = arg2;
        *(s16 *)(obj + 0x34) = 0;
        func_L00_005E4118(obj);
        return obj;
    }
    return 0;
}
