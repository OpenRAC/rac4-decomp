/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_004586F8(s32, s32);
extern s32 func_004EF078(s32, s32, s32);
extern void func_004EF430(s32, s32, s32);
extern void func_004EF608(void);

extern s32 D_0021DAD8;
extern s32 D_00221EA8;
extern s32 D_00221EAC;
extern s32 D_00221EB0;
extern s32 D_00221EB4;
extern s32 D_00221EB8;
extern s32 D_00221EBC;
extern s32 D_00221EC0;
extern s32 D_00221EC4;
extern s32 D_00221EC8;
extern s32 D_00221ECC;
extern s32 D_00221ED0;
extern s32 D_00221ED4;
extern s32 D_00221ED8;
extern s32 D_00221EE0[];

s32 func_004EEEB0(s32 arg0, s32 arg1, s32 (*alloc)(s32, s32), s32 arg3, s32 arg4)
{
    s32 i;
    s32 ret;
    s32 flag;

    D_00221EB8 = alloc(0xEC800, 0x40);
    D_00221ED0 = alloc(0xC, 0x40);
    D_00221EA8 = alloc(0x14, 0x40);
    D_00221ED8 = alloc(0x68, 0x40);
    D_00221ED4 = alloc(0xB8, 0x40);
    D_00221EB4 = alloc(0x1010, 0x40);
    D_00221ECC = alloc(0x3000, 0x40);
    for (i = 0; i < 2; i++) {
        D_00221EE0[i] = alloc(0x4000, 0x80);
    }
    D_00221EC8 = alloc(0x4000, 0x40);
    D_00221EC0 = alloc(0xC000, 0x40);
    D_00221EBC = alloc(0x5000C, 0x40);
    D_00221EB0 = alloc(0x4FC80, 0x40);
    D_00221EC4 = alloc(0x80000, 0x40);
    D_00221EAC = alloc(0x1A0000, 0x40);
    flag = arg4 != 0;
    func_004586F8(flag, flag);
    func_004EF430(arg0, arg1, arg3);
    ret = func_004EF078(D_00221ED4, D_00221EBC, D_00221ED0);
    func_004EF608();
    D_0021DAD8 &= ~0x80;
    return ret;
}
