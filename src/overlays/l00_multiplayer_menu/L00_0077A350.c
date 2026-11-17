#include "common.h"

extern s32 D_002233A4;
extern u16 D_002218E0[];
extern u8 D_172160[];
extern void func_0011A518(void *, s32, s32);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015A050(void);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern void func_0015D4E8();
extern void func_0015D4C0();
extern s32 func_1ED7D30(void *, void *, void *, s32, s32);
extern s32 func_L00_00774650(void *, s32);

/* Start a blocking network operation and pump it until done. */
s32 func_L00_0077A350(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *g = (u8 *)D_002233A4;
    s32 sp[9];
    u8 *tbl;

    func_0011A518(sp, 0, 0x24);
    *(u16 *)sp = D_002218E0[0];
    sp[6] = 0x33C;
    *(s32 *)(arg0 + 0x180) = arg1;
    *(s32 *)(arg0 + 0x178) = arg2;
    sp[7] = 1;
    sp[8] = 1;
    arg0[0x176] = 1;
    *(s32 *)(arg0 + 0x17C) = 0;
    g[0] = 1;
    *(s32 *)(g + 8) = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_1ED7D30(sp, func_0015D4E8, func_0015D4C0, 0, 0));
    tbl = D_172160;
    while (arg0[0x176] != 0) {
        if (func_0015B558() != 0 || *(s32 *)(tbl + 0x2C4) != 0) {
            *(s32 *)(g + 0x10) = 0x65;
            if (*(s32 *)(g + 0x14) == 0) {
                *(s32 *)(g + 0x14) = 0x65;
            }
            break;
        }
        g[0x1C] = 1;
        func_0015A050();
        g[0x1C] = 0;
        if (func_L00_00774650(g, 1) == 0) {
            break;
        }
    }
    g[0] = 0;
    arg0[0x176] = 0;
    return *(s32 *)(arg0 + 0x17C);
}
