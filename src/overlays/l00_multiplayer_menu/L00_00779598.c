#include "common.h"

extern s32 D_002233A4;
extern u16 D_002218E0[];
extern u8 D_172160[];
extern u8 func_00161270(void);
extern s32 func_00161310(s32 a0);
extern char *func_0011A9EC(char *, char *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern void func_0015D470(void);
extern s32 func_01ED6380(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_00773B18(void *arg0);
extern s32 func_L00_00774650(void *, s32);
extern s32 func_L00_0077A178(void *);

/* Runs the menu step: seeds the state block, polls the menu until idle, then clears the flags and returns the result. */
s32 func_L00_00779598(u8 *arg0, s32 arg1) {
    u8 sp[0x30];
    u8 *s0;
    u8 *s3;
    s32 var_s2;
    s32 one;

    s0 = (u8 *)D_002233A4;
    if (func_00161270() != 0) {
        if (func_00161310(1) != 0) {
            *(s32 *)(s0 + 0x10) = 7;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 7;
            }
            return 0;
        }
    }
    *(u16 *)sp = D_002218E0[0];
    func_0011A9EC((char *)(sp + 0x15), *(char **)(s0 + 0x64));
    arg0[0x154] = 1;
    s0[0] = 1;
    var_s2 = 1;
    one = 1;
    *(s32 *)(s0 + 8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED6380(sp, (s32)func_0015D470, 0));
    s3 = D_172160;
    for (;;) {
        if (arg0[0x154] == 0) {
            break;
        }
        if ((func_0015B558() != 0) || (*(s32 *)(s3 + 0x2C4) != 0)) {
            *(s32 *)(s0 + 0x10) = 0x56;
            if (*(s32 *)(s0 + 0x14) == 0) {
                *(s32 *)(s0 + 0x14) = 0x56;
            }
            var_s2 = 0;
            break;
        }
        s0[0x1C] = one;
        func_0015A050();
        s0[0x1C] = 0;
        if (func_L00_00774650(s0, 1) == 0) {
            var_s2 = 0;
            break;
        }
    }
    s0[0] = 0;
    arg0[0x154] = 0;
    if ((var_s2 != 0) && (*(s32 *)(arg0 + 0x170) < 0)) {
        *(s32 *)(s0 + 0x10) = 0x56;
        if (*(s32 *)(s0 + 0x14) == 0) {
            *(s32 *)(s0 + 0x14) = 0x56;
        }
        var_s2 = 0;
    }
    if (arg0[0x11E] != 0) {
        var_s2 = (func_L00_0077A178(arg0) == 0) ? 0 : var_s2;
    }
    if (arg1 != 0) {
        func_L00_00773B18(s0);
    }
    return var_s2;
}
