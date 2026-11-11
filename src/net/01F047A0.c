/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct O_01F047A0 {
    u8 pad0[0xB8];
    s32 unkB8;
} O_01F047A0;

extern s32 func_00121FA0(s32, char *);
extern s32 func_01EE3A18(s32, char *);
extern void func_01EEFB78(s32, s32);
extern void func_01F0C090(char *, s32);
extern char D_0019E090[];
extern char D_0019E0A0[];
extern char D_0019E0B0[];
extern char D_0019E0B8[];
extern char D_0019E0C8[];
extern char D_0019E0D0[];

s32 func_01F047A0(O_01F047A0 *arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 v;

    a = func_01EE3A18(arg1, D_0019E0A0);
    b = func_01EE3A18(arg1, D_0019E0B0);
    if (a != 0 && b != 0) {
        func_01EEFB78(a, b);
    } else {
        func_01F0C090(D_0019E090, 0x6C);
        return 0;
    }
    v = func_01EE3A18(arg1, D_0019E0B8);
    if (v != 0) {
        if (func_00121FA0(v, D_0019E0C8) == 0) {
            arg0->unkB8 = 0;
        } else if (func_00121FA0(v, D_0019E0D0) == 0) {
            arg0->unkB8 = 1;
        } else {
            func_01F0C090(D_0019E090, 0x7F);
            return 0;
        }
    }
    return 1;
}
