/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern u32 func_01EED8A4(s32, s32, s32);
extern void func_01EE68FC(void *, s8 *, s32);
extern s32 func_01EF4188(void *, s32, s32, s32, s32);
extern void func_01F0C090(const char *, s32);
extern char D_0019C670[];

// Checks the object's ids and handler state, calls its vtable slot, then forwards to func_01EF4188.
s32 func_01EF28AC(void *arg0, void *arg1) {
    s32 s1;
    s32 s2;
    s8 *a1;
    s32 (*vf)(void *);

    s1 = *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x80) + 4);
    if (*(s32 *)arg0 == 0) {
        func_01F0C090(D_0019C670, 0x71);
    }
    if (s1 == 0) {
        func_01F0C090(D_0019C670, 0x72);
    }
    if (arg1 == 0) {
        func_01F0C090(D_0019C670, 0x73);
    }
    vf = *(s32 (**)(void *))((u8 *)*(void **)((u8 *)arg0 + 0xB0) + 0x20);
    if (vf(arg0) == 0) {
        return 1;
    }
    if (func_01EED8A4(s1, 0x11, 0x10) != 0) {
        if (*(s32 *)((u8 *)arg1 + 0x5B10) == 0) {
            a1 = *(s8 **)((u8 *)arg0 + 0x144);
            if (a1 != 0 && *a1 != 0) {
                func_01EE68FC(arg1, a1, *(s32 *)((u8 *)arg0 + 0x148));
                return 0;
            }
        }
    }
    if (func_01EED8A4(s1, 0x11, 0) != 0 || func_01EED8A4(s1, 0x11, 1) != 0 ||
        func_01EED8A4(s1, 0x11, 2) != 0 || func_01EED8A4(s1, 0x11, 3) != 0) {
        s2 = *(s32 *)*(void **)((u8 *)arg0 + 0x80);
        if (s2 == 0) {
            func_01F0C090(D_0019C670, 0x8B);
        }
        return func_01EF4188(arg0, s1, s2, *(s32 *)arg0, (s32)arg1) == 0;
    }
    return 1;
}
