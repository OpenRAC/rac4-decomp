/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct N_01EB36A0 {
    u8 pad0[0x8];
    s32 unk8;
    u8 padC[0x14 - 0xC];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} N_01EB36A0;

extern void func_0011A370(s32, s32, s32);
extern s32 func_01EA90F0(s32);
extern void func_01EA94D0(s32 *, s32);
extern void func_01EAE2C0(s32, s32);
extern s32 func_01EB2EE0(s32);
extern N_01EB36A0 *func_01EB2F20(void);
extern void func_01EB2FF0(s32, N_01EB36A0 *);
extern N_01EB36A0 *func_01EB3028(s32, s32);

s32 func_01EB36A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 ctx;
    N_01EB36A0 *n;

    ctx = func_01EA90F0(arg0);
    if (ctx == 0) {
        return -1;
    }
    if (func_01EB2EE0(arg2) != 0) {
        return -1;
    }
    n = func_01EB3028(ctx, arg1);
    if (n == NULL) {
        n = func_01EB2F20();
        n->unk8 = arg1;
        func_01EB2FF0(ctx, n);
    }
    if (n->unk1C == 0) {
        func_01EA94D0(&n->unk1C, 0x40);
    }
    if (n->unk14 == 0) {
        func_01EA94D0(&n->unk14, 0x10C);
    }
    if (n->unk18 == 0) {
        func_01EA94D0(&n->unk18, 0x10C);
    }
    func_0011A370(n->unk1C, arg2, 0x40);
    func_01EAE2C0(n->unk14, arg2);
    func_01EAE2C0(n->unk18, arg2);
    return 0;
}
