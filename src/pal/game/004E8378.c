#include "common.h"

s32 D_0022078C = 0;

void func_00453DF8(s32 arg0);

void func_004E8378(s32 arg0)
{
    if (arg0 == D_0022078C) {
        return;
    }
    while ((*(volatile s32 *)0x10008000 & 0x100) != 0) {
        func_00453DF8(0x10);
    }
    *(volatile s32 *)0x10008020 = 0;
    *(volatile s32 *)0x10008030 = arg0 & 0x0FFFFFFF;
    *(volatile s32 *)0x10008000 = 0x145;
    D_0022078C = arg0;
    while ((*(volatile s32 *)0x10008000 & 0x100) != 0) {
        func_00453DF8(0x10);
    }
}
