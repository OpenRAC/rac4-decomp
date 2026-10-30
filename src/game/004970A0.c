#include "common.h"

extern void func_004534D0(s32 arg0);
extern void func_00499C80(void);
extern s32 D_2F32CC[];
extern s32 D_00221534;

// Calls func_004534D0 on each 0x54-byte entry of the 0x150-byte table at D_2F32CC, bumps a counter, then calls func_00499C80.
void func_004970A0(void) {
    u8 *p = (u8 *)D_2F32CC;
    u8 *end = (u8 *)D_2F32CC + 0x150;

    do {
        func_004534D0((s32)p);
        p += 0x54;
    } while ((s32)p < (s32)end);
    D_00221534 = D_00221534 + 1;
    func_00499C80();
}
