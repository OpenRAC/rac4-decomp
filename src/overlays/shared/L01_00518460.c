#include "common.h"

extern s32 func_0058FF38(s32, s32);
extern void func_005919B8(void *, s32, s32, f32);
extern void func_00591BD8(void *, s32, s32);

// The first time (bit 0 of +0xBE not yet set), compares the byte at +0x54 with func_0058FF38(0, 2)
// and, if they differ, calls func_005919B8 with a second func_0058FF38(0, 2); when bit 1 of +0x55
// is set, calls func_00591BD8(arg0, 0, -1).
void func_L01_00518460(u8 *arg0) {
    s32 first;
    u8 flags = arg0[0xBE];

    if ((flags ^ 1) & 1) {
        first = 1;
        arg0[0xBE] = flags | 1;
    } else {
        first = 0;
    }
    if (first != 0) {
        u8 anim = arg0[0x54];
        if (anim != func_0058FF38(0, 2)) {
            func_005919B8(arg0, func_0058FF38(0, 2), 10, 0.0f);
        }
    }
    if (arg0[0x55] & 2) {
        func_00591BD8(arg0, 0, -1);
    }
}
