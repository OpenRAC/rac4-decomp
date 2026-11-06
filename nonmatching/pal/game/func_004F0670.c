/* Not matching yet on PAL: BYTES 17/152 (8 words differ) (tools/check_func.py --version pal func_004F0670 --diff). Not part of the build. */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
#include "common.h"
extern u32 D_1000E000;

/* Interface reference: OpenRAC/OpenRAC @ 73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde,
 * games/rac3/ntsc/src/frontbin/3A9CF8.c, func_003AAA00.
 * Independently reconstructed and checked against RAC4 PAL retail. */
typedef struct {
    u8 pad[0xB0];
    s32 fB0;
} Type1;

extern s32 D_00221FBC;
extern s32 D_00221FA8;
extern s32 D_00221FE8;
extern Type1 *D_00221FD4;
extern s32 D_00221FD8;
extern s32 D_00221FD0;
extern u8 D_001599D8[];
extern void func_004F19F8(s32);
extern void func_004F3328(s32);
extern void func_001269F0(s32);
extern void func_001269B0(s32);
extern s32 func_001276D0(s32);
extern void func_001268D0(s32, s32);
extern void func_00139940(u8 *);
extern void func_004F2CC0(Type1 *);
extern void func_004F07D0(s32);
extern void func_004F1AF0(s32);

void func_004F0670(void)
{
    func_004F19F8(D_00221FBC);
    func_004F3328(D_00221FA8);
    func_001269F0(D_00221FE8);
    func_001269B0(D_00221FE8);
    func_001276D0(2);
    func_001268D0(2, D_00221FD4->fB0);
    func_00139940(D_001599D8);
    func_004F2CC0(D_00221FD4);
    func_004F07D0(D_00221FD8);
    func_004F1AF0(D_00221FD0);
    D_1000E000 &= 0xFFFFFFFD;
}
