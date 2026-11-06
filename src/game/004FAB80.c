#include "common.h"

extern s32 func_004F6498(s32 *p, s32 n);
extern void func_004F8EA0(u8 *arg0);
extern void func_004FAF08(void);
extern s32 D_0021DEC8;
extern s32 D_0021DF34;
extern s32 D_001DFCF4[];
extern s32 D_0021DEFC;
extern s32 D_0021DF04;
extern s32 D_0021DF08;
s32 D_00220A1C = 0;

// Allocates three buffers, builds the identity byte table and sets flag bit 2.
void func_004FAB80(void) {
    u8 buf[256];
    s32 base;
    s32 i;
    u8 *p;

    base = 0x37E000;
    D_0021DF08 = func_004F6498(&base, 0x40000);
    D_0021DEFC = func_004F6498(&base, 0x40000);
    D_0021DF34 = func_004F6498(&base, 0x400);
    D_0021DF04 = D_001DFCF4[0];
    func_004FAF08();
    D_00220A1C = 0;
    i = 255;
    p = &buf[255];
    do {
        *p = i;
        i--;
        p--;
    } while (i >= 0);
    func_004F8EA0(buf);
    D_0021DEC8 |= 2;
}
