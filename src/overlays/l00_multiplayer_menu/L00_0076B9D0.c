#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED52A0(u8 *obj, s32 arg1, s32 arg2);
extern void func_0015CE30();
extern u16 D_002217E0[];
extern u8 *D_002233A4;

/* Starts a request for the object when it is enabled; returns 0 if the follow-up call fails. */
s32 func_L00_0076B9D0(u8 *arg0, s32 arg1) {
    u8 b[0x38];
    void *q;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    r = 1;
    if (arg0[0x531] != 0) {
        q = *(void **)(D_002233A4 + 0x64);
        arg0[0x530] = arg1;
        *(u16 *)b = D_002217E0[0];
        func_0011A9EC(b + 0x15, q);
        x = *(s32 *)arg0;
        y = *(s32 *)(arg0 + 0x544);
        arg0[0x538] = 1;
        z = arg0[0x530];
        *(s32 *)(b + 0x28) = x;
        *(s32 *)(b + 0x2C) = z;
        *(s32 *)(b + 0x30) = 1;
        *(s32 *)(b + 0x34) = y;
        *(s32 *)(arg0 + 0x53C) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_01ED52A0(b, (s32)func_0015CE30, 0));
        if (func_0015B558() != 0) {
            r = 0;
        }
    }
    return r;
}
