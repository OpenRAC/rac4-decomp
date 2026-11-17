#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_00146D10(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7658(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_01ED76D8(u8 *obj, s32 arg1, s32 arg2);
extern void func_0015D538(void);
extern u16 D_00221928[];
extern s32 D_002233A4;
typedef struct {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x64 - 0x18];
    void *f64;
} Type3;
/* Sets two flag bytes and a 32-bit value in obj, sends a request built from D_00221928 through func_01ED76D8 or func_01ED7658 by arg1, and sets the timers at +0x10/+0x14 to 0x5E when func_0015B558 is non-zero. */
s32 func_L00_0077BDF0(u8 *arg0, s32 arg1) {
    u8 sp[0x30];
    Type3 *g = (Type3 *)D_002233A4;
    void *temp_v1 = g->f64;
    s32 var_s2;
    arg0[0x2F89] = 1;
    arg0[0x2F8A] = arg1;
    var_s2 = 1;
    if (arg1 != 0) {
        *(u16 *)sp = D_00221928[0];
        func_0011A9EC(sp + 0x15, temp_v1);
        *(s32 *)(sp + 0x28) = func_00146D10();
        *(s32 *)(arg0 + 0x2F8C) = func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_01ED76D8(sp, (s32)func_0015D538, 0));
    } else {
        *(u16 *)sp = D_00221928[0];
        func_0011A9EC(sp + 0x15, temp_v1);
        *(s32 *)(sp + 0x28) = func_00146D10();
        *(s32 *)(arg0 + 0x2F8C) = func_0012FEB0(func_0012E370(), 0x24000);
        func_0015B548(func_01ED7658(sp, (s32)func_0015D538, 0));
    }
    if (func_0015B558() != 0) {
        g->f10 = 0x5E;
        if (g->f14 == 0) {
            g->f14 = 0x5E;
        }
        var_s2 = 0;
    }
    return var_s2;
}
