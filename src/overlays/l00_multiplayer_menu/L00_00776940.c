#include "common.h"

extern char *func_0011A9EC(char *, char *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7048(u8 *obj, s32 arg1, s32 arg2);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern u16 D_00221878[];
extern s32 D_002233A4;
extern u8 D_172160[];
extern void func_0015D308();

/* starts a blocking network request and pumps it until done; returns the result buffer on success */
u8 *func_L00_00776940(u8 *arg0, s32 arg1) {
    u8 *g = (u8 *)D_002233A4;
    s32 sp[20];
    u8 *tbl;
    char *name = *(char **)(g + 0x64);
    s32 ok;
    s32 err;
    s32 code;
    u8 *ret;

    *(u16 *)sp = D_00221878[0];
    func_0011A9EC((char *)sp + 0x15, name);
    sp[11] = arg1;
    sp[10] = 0;
    arg0[0x14C] = 1;
    g[0] = 1;
    *(s32 *)(g + 8) = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED7048((u8 *)sp, (s32)func_0015D308, 0));
    tbl = D_172160;
    ok = 1;
    while (arg0[0x14C] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tbl + 0x2C4) != 0) {
            *(s32 *)(g + 0x10) = 0x48;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x48;
            }
            ok = 0;
            break;
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
    ret = 0;
    arg0[0x14C] = 0;
    if (ok != 0) {
        err = *(s32 *)(arg0 + 0x168);
        if (err == -0x3DD) {
            code = 0x47;
        } else if (err != 0) {
            code = 0x48;
        } else {
            goto done;
        }
        *(s32 *)(g + 0x10) = code;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = code;
        }
        ok = 0;
    done:
        ret = ok ? arg0 + 0x150 : 0;
    }
    return ret;
}
