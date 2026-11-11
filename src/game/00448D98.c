/* cflags: -fno-schedule-insns */
#include "common.h"

extern u8 *D_00221E20;
extern u8 *D_00221200;
extern u8 *D_002211FC;
extern void func_00469968(void);
extern u8 *func_004E7B88(void);

void func_00448D98(void)
{
    s32 tag;
    u8 *packet;

    D_00221200 = D_00221E20;
    tag = 0x20000000;
    D_00221E20 += 16;
    *(s32 *)D_002211FC = tag;
    packet = D_002211FC;
    *(u8 **)(packet + 4) = D_00221E20;
    *(s32 *)(D_002211FC + 8) = 0;
    *(s32 *)(D_002211FC + 12) = 0;
    func_00469968();
    func_004E7B88();
    *(s32 *)D_00221E20 = tag;
    *(u8 **)(D_00221E20 + 4) = D_002211FC + 16;
    *(s32 *)(D_00221E20 + 8) = 0;
    *(s32 *)(D_00221E20 + 12) = 0;
    D_00221E20 += 16;
    *(s32 *)D_00221200 = tag;
    *(u8 **)(D_00221200 + 4) = D_00221E20;
    *(s32 *)(D_00221200 + 8) = 0;
    *(s32 *)(D_00221200 + 12) = 0;
}
