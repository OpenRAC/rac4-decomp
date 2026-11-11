/* cflags: -fno-schedule-insns */
#include "common.h"

extern u8 *D_00221E20;
extern u8 *D_00221CF8;
extern u8 *D_00221CF4;
extern s32 D_0021DA34;
extern s32 D_0021DA30;
extern void func_00469968(void);
extern u8 *func_004E7B88(void);

void func_004DEF78(void)
{
    s32 tag;
    u8 *packet;

    D_00221CF8 = D_00221E20;
    tag = 0x20000000;
    D_00221E20 += 16;
    *(s32 *)D_00221CF4 = tag;
    packet = D_00221CF4;
    *(u8 **)(packet + 4) = D_00221E20;
    *(s32 *)(D_00221CF4 + 8) = 0;
    *(s32 *)(D_00221CF4 + 12) = 0;
    func_00469968();
    func_004E7B88();
    *(s32 *)D_00221E20 = tag;
    *(u8 **)(D_00221E20 + 4) = D_00221CF4 + 16;
    *(s32 *)(D_00221E20 + 8) = 0;
    *(s32 *)(D_00221E20 + 12) = 0;
    D_00221E20 += 16;
    *(s32 *)D_00221CF8 = tag;
    *(u8 **)(D_00221CF8 + 4) = D_00221E20;
    *(s32 *)(D_00221CF8 + 8) = 0;
    *(s32 *)(D_00221CF8 + 12) = 0;
    D_0021DA30 = D_0021DA34;
}
