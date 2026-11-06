#include "common.h"

void func_004535E0(s32);

s32 D_002206EC = 0;

void func_004E7450(s32 arg0) {
    if (arg0 != D_002206EC) {
        if (*(volatile s32 *)0x10008000 & 0x100) {
            do {
                func_004535E0(0x10);
            } while (*(volatile s32 *)0x10008000 & 0x100);
        }
        *(volatile s32 *)0x10008020 = 0;
        *(volatile s32 *)0x10008030 = arg0 & 0x0FFFFFFF;
        *(volatile s32 *)0x10008000 = 0x145;
        D_002206EC = arg0;
        if (*(volatile s32 *)0x10008000 & 0x100) {
            do {
                func_004535E0(0x10);
            } while (*(volatile s32 *)0x10008000 & 0x100);
        }
    }
}
