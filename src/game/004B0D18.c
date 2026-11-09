#include "common.h"

extern s32 D_00221718;
extern s32 D_003D1AC8[];
extern void (*D_003095C4[])(int);
extern char D_003095D8[];
extern s32 func_00497810(u32 index);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00505040(u32 id, s32 enabled);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B70(s32 index, s32 handle);
extern void func_004B0A00(int);
extern void func_004B0AE8(int);

void func_004B0D18(void)
{
    s32 i;

    switch (func_00497810(0)) {
    case 0:
    case 2:
        func_00501638(&D_00221718, 0x13, -1);
        D_003095C4[0] = func_004B0A00;
        break;
    case 1:
    case 3:
    case 4:
        func_00501638(&D_00221718, 0x14, -1);
        D_003095C4[0] = func_004B0AE8;
        break;
    }
    for (i = 0; i < 3; i++) {
        func_00505040(func_004A1A60(&D_00221718, D_003D1AC8[i + 4]), 1);
        func_00505040(func_004A1A60(&D_00221718, D_003D1AC8[i + 11]), 1);
    }
    func_00505B70(5, D_00221718);
    func_00505238(func_004A1A60(&D_00221718, D_003D1AC8[2]), D_003095D8);
    func_00505238(func_004A1A60(&D_00221718, D_003D1AC8[3]), D_003095D8 + 8);
    func_00505238(func_004A1A60(&D_00221718, D_003D1AC8[9]), D_003095D8 + 0x34);
    func_00505238(func_004A1A60(&D_00221718, D_003D1AC8[10]), D_003095D8 + 0x3C);
}
