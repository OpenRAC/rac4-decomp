/* cflags: -fno-schedule-insns */
/* Reference: OpenRAC/rac2-decomp @ 99f35ac2c084fc59cdf3d631f8f960a825e7a49c; func_0027C660 (src/game/0027C660-rc2.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

extern u8 *D_00221F20;
extern u8 *D_00221300;
extern u8 *D_002212FC;
extern void func_0046A228(void);
extern u8 *func_004E8AB0(void);

/* Completes a command-chain block and links the next buffer position. */
void func_004493D8(void)
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
