/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern void func_01EF0D44(void *arg0);
extern void func_01EF1E4C(void *, s32, s32);
extern void func_01EF1F70(void *, void *);
extern void func_01EF2190(void *, s32);
extern void func_01F0C090(const char *, s32);
extern s32 D_0019C400[];

/* Clears two stack buffers, runs the setup chain, and reports to the log when arg3 is not 0x21. */
void func_01EEEFD0(s32 unused, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp[0x80];
    u8 *sp70;

    if (arg3 != 0x21) {
        func_01F0C090(D_0019C400, 0x3CE);
    }
    func_0011A518(sp, 0, 0x70);
    sp70 = sp + 0x70;
    func_0011A518(sp70, 0, 0x10);
    func_01EF0D44(sp);
    func_01EF1E4C(sp, arg1, 0x1388);
    func_01EF1F70(sp, sp70);
    func_01EF2190(sp70, arg2);
}
