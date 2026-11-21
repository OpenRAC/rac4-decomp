#include "common.h"

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED4F18(u8 *obj, s32 arg1, s32 arg2);
extern s64 func_L00_00769DE0(void *);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern void func_0015D0B0(void);
extern u16 D_002217E0[];
extern s32 D_002233A4;
extern u8 D_172160[];

/* Start a request on the state object, wait for it to finish, then record the result code and check for the follow-up step. */
s64 func_L00_007687A8(u8 *arg0, s32 arg1) {
    u8 *g = (u8 *)D_002233A4;
    s32 sp[12];
    u8 *tbl;
    s32 busy;
    s64 ok = 1;
    s32 v;
    char *name;

    name = *(char **)(g + 0x64);
    *(u16 *)sp = D_002217E0[0];
    func_0011A9EC((u8 *)sp + 0x15, name);
    sp[10] = arg1;
    arg0[0x88] = 1;
    g[0] = 1;
    *(s32 *)(g + 8) = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED4F18((u8 *)sp, (s32)func_0015D0B0, 0));
    busy = 1;
    tbl = D_172160;
    while (arg0[0x88] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tbl + 0x2C4) != 0) {
            *(s32 *)(g + 0x10) = 0x1F;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x1F;
            }
            ok = 0;
            break;
        }
        g[0x1C] = busy;
        func_0015A050();
        g[0x1C] = 0;
        if (func_L00_00774650(g, 1) == 0) {
            ok = 0;
            break;
        }
    }
    g[0] = 0;
    arg0[0x88] = 0;
    if (ok != 0) {
        v = *(s32 *)(arg0 + 0x8C);
        if (v == -0x3DE) {
            v = 0x23;
        } else if (v != 0) {
            v = 0x1F;
        } else {
            goto skip;
        }
        *(s32 *)(g + 0x10) = v;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = v;
        }
        ok = 0;
skip:
        if (ok != 0 && arg0[0x408] != 0 && arg0[0x410] == 0) {
            ok = func_L00_00769DE0(arg0);
        }
    }
    return ok;
}
