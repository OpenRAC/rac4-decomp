#include "common.h"

extern char *func_0011A9EC(char *, char *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED6F48(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern void func_0015D0D8(void);
extern u16 D_00221808[];
extern s32 D_002233A4;
extern u8 D_172160[];

/* Runs the modal wait loop until the flag at +0x10 clears; returns the +0x284 block unless an error was recorded. */
u8 *func_L00_0076F548(u8 *arg0, s32 arg1) {
    u8 *g = (u8 *)D_002233A4;
    s32 sp[12];
    u8 *tbl;
    s32 ok;
    s32 v;

    arg0[3] = 0;
    *(u16 *)sp = D_00221808[0];
    func_0011A9EC((char *)sp + 0x15, *(char **)(g + 0x64));
    sp[10] = arg1;
    arg0[0x10] = 1;
    g[0] = 1;
    *(s32 *)(g + 8) = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED6F48((u8 *)sp, (s32)func_0015D0D8, 0));
    tbl = D_172160;
    ok = 1;
    while (arg0[0x10] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tbl + 0x2C4) != 0) {
            *(s32 *)(g + 0x10) = 0x38;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x38;
            }
            ok = 0;
        }
        g[0x1C] = 1;
        func_0015A050();
        g[0x1C] = 0;
        if (func_L00_00774650(g, 1) == 0) {
            ok = 0;
            break;
        }
    }
    g[0] = 0;
    arg0[0x10] = 0;
    if (ok != 0) {
        v = *(s32 *)(arg0 + 0x29C);
        if (v == -0x3DF || v == -0x3D1) {
            v = 0x3F;
        } else if (v != 0) {
            v = 0x38;
        } else {
            goto done;
        }
        *(s32 *)(g + 0x10) = v;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = v;
        }
        ok = 0;
    }
done:
    return ok ? arg0 + 0x284 : 0;
}
