#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern f32 *func_00476690(void *);
extern s32 func_00476660(void *);
extern s32 func_L01_005AE158(void *);
extern void func_L01_005A24D0(void *, s32);
extern void func_00484710(void *, s32, s32);
extern void func_00473A88(void *, s32, s32);
extern void func_L00_005F15B8(void *);
extern void func_005A85F8(void *, s32, s32);
extern s32 func_L01_005A2F40(void *, void *);
extern void func_L01_005A1B38(void *);
extern void func_004771B0(void *, s32);

s32 func_L01_0048DF40(u8 *arg0, u8 *arg1) {
    f32 *value;
    f32 old;
    u8 *obj;

    if (*(u8 **)(arg1 + 0x170) == NULL) {
        return arg0[0x20] != 1;
    }
    value = func_00476690(*(u8 **)(arg1 + 0x170));
    if (value == NULL) {
        return 1;
    }
    if (func_00476660(*(u8 **)(arg1 + 0x170)) == 0) {
        return 1;
    }
    old = *value;
    if (func_L01_005AE158(*(u8 **)(arg1 + 0x170)) != 0 || *value < old) {
        func_L01_005A24D0(arg0, 0xF0);
    }
    if (*value <= 0.0f) {
        func_00484710(*(u8 **)(arg1 + 0x170), -1, 0);
        func_00473A88(arg0, 5, 4);
    }
    obj = *(u8 **)(arg1 + 0x170);
    if (((*(u64 *)(obj + 0x30) & ((u64)0x8208 << 29)) != ((u64)0x8200 << 23) || *(s32 *)(obj + 0x98) != 0) &&
        *value > 0.0f) {
        func_L00_005F15B8(obj);
        func_005A85F8(arg0, 5, -1);
    }
    if (*(s32 *)(arg1 + 0x60) != 0 && func_L01_005A2F40(arg0, arg1 + 0x50) != 0) {
        arg1[0x1D6] = 1;
        *(u128 *)(arg1 + 0xD60) = *(u128 *)(arg1 + 0x50);
    }
    func_L01_005A1B38(arg0);
    func_004771B0(*(u8 **)(arg1 + 0x170), 0);
    return 0;
}
