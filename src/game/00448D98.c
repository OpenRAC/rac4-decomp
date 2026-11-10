/* cflags: -fno-schedule-insns */
#include "common.h"

extern u8 *D_00221F20;
extern u8 *D_00221300;
extern u8 *D_002212FC;
extern void func_0046A228(void);
extern u8 *func_004E8AB0(void);

void func_00448D98(void)
{
    s32 tag;
    u8 *packet;

    D_00221300 = D_00221F20;
    tag = 0x20000000;
    D_00221F20 += 16;
    *(s32 *)D_002212FC = tag;
    packet = D_002212FC;
    *(u8 **)(packet + 4) = D_00221F20;
    *(s32 *)(D_002212FC + 8) = 0;
    *(s32 *)(D_002212FC + 12) = 0;
    func_0046A228();
    func_004E8AB0();
    *(s32 *)D_00221F20 = tag;
    *(u8 **)(D_00221F20 + 4) = D_002212FC + 16;
    *(s32 *)(D_00221F20 + 8) = 0;
    *(s32 *)(D_00221F20 + 12) = 0;
    D_00221F20 += 16;
    *(s32 *)D_00221300 = tag;
    *(u8 **)(D_00221300 + 4) = D_00221F20;
    *(s32 *)(D_00221300 + 8) = 0;
    *(s32 *)(D_00221300 + 12) = 0;
}
