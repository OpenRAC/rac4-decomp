#include "common.h"

extern s32 D_0021DF50;
extern s32 D_0021DF64;
extern s32 D_0021DF68;
extern s32 D_0021DF6C;
extern s32 D_0021DF70;
extern s32 D_0021DF78;
extern s32 D_0021DF7C;
extern s32 D_0021DF80;
extern s32 D_0021DFA8;
extern s32 D_0021DFAC;
extern s32 D_0021DFB0;
extern s32 D_0021DFB4;
extern s32 D_00222078;
extern s32 D_0022207C;
extern s32 D_00222080;
extern s32 D_00328F00[];
extern s32 D_001DFD70[];
extern u8 D_0020E380[];
extern u8 D_0020E480[];
extern u8 D_0020F480[];

s32 func_004F7518(s32 *, s32);
void func_00126E20(s32);
void func_004FAFA8(u8 **, s32 *);
void func_004FB418(u8 **, s32 *);
void func_004FB8B8(u8 **, s32 *);

// Sets four fixed addresses, takes three 0x40000-byte blocks from 0x378000,
// fills a 256-entry table and runs three setup routines on their buffers.
void func_004FADB8(void) {
    s32 base;
    u8 *p;
    s32 n;
    s32 i;
    s32 v;
    s32 w;

    v = 0x3F8000;
    D_0021DF64 = v;
    D_0021DF68 = 0x3FC000;
    D_0021DFB4 = 0x3FE000;
    D_0021DF80 = 0x400000;
    v = 0x378000;
    base = v;
    D_0021DF70 = func_004F7518(&base, 0x40000);
    base = v;
    D_0021DF78 = func_004F7518(&base, 0x40000);
    D_0021DF7C = func_004F7518(&base, 0x40000);
    for (i = 0; i < 0x100; i++) {
        w = (i & 0xE7) | ((i & 8) << 1) | ((i & 0x10) >> 1);
        if (w < 0x80) {
            D_00328F00[i] = 0;
        } else {
            D_00328F00[i] = (w - 0x7F) << 24;
        }
    }
    func_00126E20(0);
    p = D_0020E380;
    D_0021DF6C = D_001DFD70[1];
    n = 0;
    func_004FAFA8(&p, &n);
    D_0021DFA8 = p - D_0020E380;
    D_00222078 = n;
    p = D_0020E480;
    n = 0;
    func_004FB418(&p, &n);
    D_0021DFAC = p - D_0020E480;
    D_0022207C = n;
    p = D_0020F480;
    n = 0;
    func_004FB8B8(&p, &n);
    D_0021DF50 |= 1;
    D_0021DFB0 = p - D_0020F480;
    D_00222080 = n;
}
