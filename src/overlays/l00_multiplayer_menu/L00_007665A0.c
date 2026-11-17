#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7E20(u8 *obj, s32 arg1, s32 arg2);
extern u16 D_002217D0[];
extern u8 *D_002233A4;
extern u8 func_0015CC78[];

/* Starts a request once when enabled, stamping the timer; returns 0 if it was submitted OK. */
s32 func_L00_007665A0(u8 *p) {
    s32 buf[8];
    s32 r;
    u8 *o;
    r = 1;
    o = *(u8 **)(D_002233A4 + 0x64);
    if (*p != 0 && p[8] == 0 && o[0x11E] != 0) {
        *(u16 *)buf = D_002217D0[0];
        p[8] = 1;
        *(s32 *)(p + 0xC) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_01ED7E20((u8 *)buf, (s32)func_0015CC78, 0));
        if (func_0015B558() != 0) r = 0;
    }
    return r;
}
