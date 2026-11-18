/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -fno-gcse -mno-split-addresses */
#include "common.h"

extern s32 D_0016E430[];
extern char D_0019C400[];
extern s32 func_0011AE00(char *, char *, s32);
extern void func_01EE7EEC(s32, void *);
extern void func_01EE955C(s32, s32);
extern void func_01EEEFD0(s32 unused, s32 arg1, s32 arg2, s32 arg3);
extern void func_01F04538(s32, void *, s32);
extern void *func_01F07100(void);
extern s32 func_01F07554(void *e, void *arg);
extern void func_01F0C090(char *arg0, s32 arg1);

/* Checks a name against the entry, then resets and registers it. */
s32 func_01EEF088(u8 *a0, u8 *a1)
{
    char name[0x21];

    if (!*(s32 *)(a0 + 0xA4)) func_01F0C090(D_0019C400, 0x3E8);
    func_01EE955C(*(s32 *)(a0 + 0xA4), 1);
    if (!D_0016E430[0]) func_01F0C090(D_0019C400, 0x3EE);
    func_01EEEFD0((s32)a0, (s32)a1, (s32)name, 0x21);
    if (func_0011AE00(name, (char *)(a1 + 0x1B78), 0x21)) return 0;
    func_01F04538(*(s32 *)(a0 + 0x30C4), a1 + 0x384, 0x1000);
    func_01EE7EEC(*(s32 *)(a0 + 0xA4), a1);
    func_01F07554(func_01F07100(), a1);
    *(s32 *)(a1 + 0x1384) = 0;
    return 1;
}
