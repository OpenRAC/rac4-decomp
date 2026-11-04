/* cflags: -fno-schedule-insns */
/* Reference: OpenRAC/rac2-decomp @ 99f35ac2c084fc59cdf3d631f8f960a825e7a49c; func_002E3820 (src/game/002E3820-rc2.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

extern u8 *D_00221F20;
extern u8 *D_00221DF8;
extern u8 *D_00221DF4;
extern s32 D_0021DAB4;
extern s32 D_0021DAB0;
extern void func_0046A228(void);
extern u8 *func_004E8AB0(void);

/* PAL retail reconstruction; related command-chain algorithm is RAC2
 * 002E3820, src/game/002E3820-rc2.c. */
void func_004DFED8(void)
{
    s32 tag;
    u8 *packet;

    D_00221DF8 = D_00221F20;
    tag = 0x20000000;
    D_00221F20 += 16;
    *(s32 *)D_00221DF4 = tag;
    packet = D_00221DF4;
    *(u8 **)(packet + 4) = D_00221F20;
    *(s32 *)(D_00221DF4 + 8) = 0;
    *(s32 *)(D_00221DF4 + 12) = 0;
    func_0046A228();
    func_004E8AB0();
    *(s32 *)D_00221F20 = tag;
    *(u8 **)(D_00221F20 + 4) = D_00221DF4 + 16;
    *(s32 *)(D_00221F20 + 8) = 0;
    *(s32 *)(D_00221F20 + 12) = 0;
    D_00221F20 += 16;
    *(s32 *)D_00221DF8 = tag;
    *(u8 **)(D_00221DF8 + 4) = D_00221F20;
    *(s32 *)(D_00221DF8 + 8) = 0;
    *(s32 *)(D_00221DF8 + 12) = 0;
    D_0021DAB0 = D_0021DAB4;
}
