#include "common.h"

extern void func_L00_007575D0(void *);
extern void func_L00_00757640(void *);
extern void func_L00_007576B8(void *);
extern s32 func_L00_00757748(void *, s32 *);
extern void func_L00_00757A90(void *);
extern s32 func_L00_00757B30(void *);
extern void func_L00_0071F8B0(void *, u32);

s32 D_L00_00221494 = 0;

/* Dispatch the current menu page and update the selected slot. */
s32 func_L00_00757460(u8 *obj, s32 arg1) {
    s32 result;
    s32 slot;
    u8 *entry;
    u8 *inner;

    result = 0;
    switch (D_L00_00221494) {
    case 0:
        func_L00_007575D0(obj);
        break;
    case 1:
        func_L00_00757640(obj);
        break;
    case 2:
        func_L00_007576B8(obj);
        break;
    case 3:
        result = func_L00_00757748(obj, &arg1);
        break;
    case 6:
        func_L00_00757A90(obj);
        break;
    case 7:
        result = func_L00_00757B30(obj);
        break;
    }
    slot = *(s32 *)(obj + 0x230);
    if (slot != -1) {
        entry = *(u8 **)(((u32)slot << 2) + obj + 0xB0);
        inner = *(u8 **)(entry + 0x58);
        func_L00_0071F8B0(obj, (*(s32 (**)(u8 *))(inner + 0x44))(entry));
    } else {
        func_L00_0071F8B0(obj, 0xFFFFFFFF);
    }
    return result;
}
