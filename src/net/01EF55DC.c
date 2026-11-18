/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern s32 func_01EA6EC0(void *arg0);
extern void func_01EA6D70(void *arg0, s32 arg1);
extern s32 func_01EA70B0(void *arg0, s32 arg1);
extern s32 func_01EA71F0(void *arg0, s32 *arg1);
extern s32 func_01EA72C8(void *arg0, s32 *arg1);
extern s32 func_01EA7538();
extern s32 func_01EA7740(u8 *arg0, s32 arg1, s32 arg2, u32 *arg3);
extern void func_01EED528(s32 arg0);
extern void func_01F0C090(char *, s32);
extern char D_0019C8C0[];

// Stores a result through arg3 and returns 1 when the step completes, 0 on failure
s32 func_01EF55DC(u8 *arg0, s32 arg1, s64 arg2, s64 *arg3) {
    s32 sp0;
    s32 sp4;
    u32 sp8;
    s32 temp_v0;
    u8 *temp_s0;

    temp_s0 = arg0 + 0x10;
    if (func_01EA6EC0(temp_s0) != 0) {
        *arg3 = 0;
        func_01EED528(0x21);
        return 0;
    }
    *arg3 = arg2;
    if (func_01EA71F0(temp_s0, &sp0) != 0) {
        return 0;
    }
    if (sp0 != 0) {
        sp4 = 0;
        if (func_01EA72C8(temp_s0, &sp4) != 0) {
            return 1;
        }
        sp8 = 0;
        temp_v0 = func_01EA7740(*(u8 **)(arg0 + 0xC), sp4, sp0, &sp8);
        *arg3 = sp8;
        if (temp_v0 == 0) {
            func_01EA6D70(temp_s0, (s32) *arg3);
            func_01EA70B0(temp_s0, 1);
            if (func_01EA7538() == 0) {
                return 1;
            }
            func_01F0C090(D_0019C8C0, 0x207);
            return 1;
        }
    } else {
        if (arg2 > 0) {
            func_01F0C090(D_0019C8C0, 0x20D);
        }
        return 1;
    }
    return 0;
}
