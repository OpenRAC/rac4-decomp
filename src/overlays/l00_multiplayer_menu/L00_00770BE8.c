#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7F88(u8 *obj, s32 arg1, s32 arg2);
extern void func_0015D178(void);
extern u16 D_00221828[];

/* start the timer for the object and report whether the follow-up query is zero */
s32 func_L00_00770BE8(u8 *arg0) {
    u8 buf[0x20];
    s32 r;

    *(u16 *)buf = D_00221828[0];
    *(u16 *)(buf + 0x18) = *(u16 *)(arg0 + 0x2C);
    *(u16 *)(buf + 0x16) = 1;
    arg0[0x20] = 1;
    *(s32 *)(arg0 + 0x24) = func_0012FEB0(func_0012E370(), 0x24000);
    r = func_01ED7F88(buf, (s32)func_0015D178, 0);
    func_0015B548(r);
    return func_0015B558() == 0;
}
