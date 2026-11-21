#include "common.h"

extern char *func_0011A9EC(char *, char *);
extern s32 func_0011AB04(u8 *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED6BB0(u8 *obj, s32 arg1, s32 arg2);
extern void func_L00_005C1758(s32 a0, s32 a1, s32 a2);
extern s32 func_L00_00774650(u8 *arg0, s32 arg1);
extern void func_0015D510(void);
extern u16 D_00221928[];
extern s32 D_002233A4;
typedef struct { u8 pad0[0x2C4]; s32 f2C4; } Type1;
extern Type1 D_172160;

// Arms the menu request for a string, polls until it answers, reports the status; returns 1 when the answer is unknown.
s32 func_L00_0077BB60(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 sp[0x70];
    u8 *g;
    s32 v;

    *(u16 *)sp = D_00221928[0];
    g = (u8 *)D_002233A4;
    func_0011A9EC((char *)(sp + 0x15), *(char **)(g + 0x64));
    *(s32 *)(sp + 0x28) = arg2;
    func_L00_005C1758((s32)(sp + 0x2C), (s32)arg1, func_0011AB04(arg1));
    arg0[0] = 1;
    g[0] = 1;
    *(s32 *)(g + 0x8) = (s32)func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_01ED6BB0(sp, (s32)func_0015D510, 0));
    while (arg0[0] != 0) {
        if (func_0015B558() == 0 && D_172160.f2C4 == 0) {
            g[0x1C] = 1;
            func_0015A050();
            g[0x1C] = 0;
            if (func_L00_00774650(g, 1) != 0) {
                continue;
            }
            v = 2;
        } else {
            v = 0x5D;
        }
        *(s32 *)(g + 0x10) = v;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = v;
        }
        arg0[0] = 0;
        return 0;
    }
    g[0] = 0;
    arg0[0] = 0;
    if (*(s32 *)(arg0 + 0x5C) == -0x3C6) {
        *(s32 *)(g + 0x10) = 3;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = 3;
        }
        return 0;
    }
    if (*(s32 *)(arg0 + 0x5C) == -0x3C7) {
        *(s32 *)(g + 0x10) = 0x5D;
        if (*(s32 *)(g + 0x14) == 0) {
            *(s32 *)(g + 0x14) = 0x5D;
        }
        return 0;
    }
    return 1;
}
