#include "common.h"

extern void func_L00_007107F0(void *arg0, void *arg1);

/* Copies the table pointers and counts from arg1 into arg0, then fills the two slot arrays and the object list. */
void func_L00_00712630(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 *p;
    u8 *obj;

    func_L00_007107F0(arg0, arg1);
    *(s32 *)(arg0 + 0x5C) = *(s32 *)(arg1 + 0x40);
    if (*(s32 *)(arg0 + 0x5C) > 0x10) {
        *(s32 *)(arg0 + 0x5C) = 0x10;
    }
    for (i = 0; i < *(s32 *)(arg0 + 0x5C); i++) {
        p = *(s32 **)(arg1 + 0x44);
        if (p != 0) {
            ((s32 *)(arg0 + 0x60))[i] = p[i];
        } else {
            ((u32 *)(arg0 + 0x60))[i] = 0xFFFFFFFF;
        }
        p = *(s32 **)(arg1 + 0x48);
        if (p != 0) {
            ((s32 *)(arg0 + 0xA0))[i] = p[i];
        } else {
            ((s32 *)(arg0 + 0xA0))[i] = 0;
        }
        p = *(s32 **)(arg1 + 0x4C);
        if (p != 0) {
            ((s32 *)(arg0 + 0xE0))[i] = p[i];
        } else {
            ((s32 *)(arg0 + 0xE0))[i] = 0;
        }
    }
    *(s32 *)(arg0 + 0x120) = *(s32 *)(arg1 + 0x50);
    if (*(s32 *)(arg0 + 0x120) > 0x100) {
        *(s32 *)(arg0 + 0x120) = 0x100;
    }
    for (i = 0; i < *(s32 *)(arg0 + 0x120); i++) {
        obj = (*(u8 ***)(arg1 + 0x54))[i];
        if (obj != 0) {
            ((u8 **)(arg0 + 0x124))[i] = obj;
            if (*(s32 *)(obj + 4) != 3) {
                (*(void (**)(void *, s32, s32))(*(u8 **)(obj + 0x58) + 0x20))(obj, 0, 0);
            }
        } else {
            ((u8 **)(arg0 + 0x124))[i] = 0;
        }
    }
    *(s32 *)(arg0 + 0x524) = *(s32 *)(arg1 + 0x58);
    *(s32 *)(arg0 + 0x52C) = *(s32 *)(arg1 + 0x5C);
    *(u8 *)(arg0 + 0x530) = 1;
    *(u8 *)(arg0 + 0x531) = 1;
}
