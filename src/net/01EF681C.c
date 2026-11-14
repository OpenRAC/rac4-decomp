/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_01EEE12C(void);
extern s32 func_01EEE13C(void);
extern s32 func_01EF308C(s32 arg0, s32 arg1, s32 *arg2);
extern s32 func_01EF339C(s32 a, void *b, void *out);
extern void func_01F0C090(const char *, s32);
extern s32 func_01F0C194();
extern s32 D_0019CB38[];
extern s32 D_0019CBA0[];
extern s32 D_0019CBB0[];

// Looks up two entries for the object at arg0 and reports if both succeed.
void func_01EF681C(s32 *arg0) {
    s32 sp0;
    s32 sp4;
    s32 temp_s0;

    if (func_01EEE12C() == 0) {
        func_01F0C090((const char *)D_0019CB38, 0xB5);
    }
    sp0 = 0;
    sp4 = -1;
    temp_s0 = func_01EF339C(*arg0, D_0019CBA0, &sp0);
    func_01EF308C(*arg0, (s32)D_0019CBB0, &sp4);
    if (temp_s0 != 0 && sp4 != -1) {
        if (func_01EEE12C() == 0) {
            func_01F0C090((const char *)D_0019CB38, 0xCB);
        }
        func_01F0C194(func_01EEE13C(), sp0, sp4);
    }
}
