#include "common.h"

extern s32 func_L00_005F13D8(void);
extern void func_L00_005F1430(s32 arg0);
extern void func_L00_005F1520(s32);
extern void func_L01_005A2D10(s32);

// Switch the object to the slot's id, then fire func_L01_005A2D10 once past its float.
void func_L01_005A2230(s32 owner, u8 *obj, s32 slot) {
    s32 off = slot << 2;
    u8 *base = obj + 0x50;
    s32 *p = (s32 *)(base + off);
    s32 id;
    if (*p == 0) {
        func_L00_005F1430(owner);
        return;
    }
    if (*(s32 *)(obj + 0x10) != *p) {
        if (*(s16 *)(obj + 0x16) == 2) func_L00_005F1520(owner);
        id = *p;
        *(s16 *)(obj + 0x18) = 0;
        *(s16 *)(obj + 0x16) = 1;
        *(s32 *)(obj + 0x10) = id;
        *(s16 *)(obj + 0x14) = ((s32 (*)(s32))func_L00_005F13D8)(id);
        *(u8 *)(obj + 0x3D) = slot;
        *(s16 *)(obj + 0x1E) = 0;
    }
    if (*(s16 *)(obj + 0x16) != 2 && (*(u16 *)(obj + 0x1C) & 2)) {
        if (*(f32 *)(obj + 0x48) <= *(f32 *)((u32)obj + (slot << 2) + 0x70)) func_L01_005A2D10(owner);
    }
}
