#include "common.h"

/* Reference: OpenRAC/OpenRAC@73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde
 * OpenRAC/games/rac3/ntsc/src/frontbin/39BC00.c func_0039C028.
 * Independently reconstructed from RAC4 PAL retail. */

typedef struct {
    u8 prefix[0x74];
    s32 count;
} State;
extern State D_00237100;
extern u32 *D_00221F20;
extern u32 D_0021DAFC;
extern u8 D_0020C220[];
extern s32 D_0023A900[];
extern void func_00449D20(void), func_00449E80(void);
void func_00489550(u32 *buffer)
{
    D_00221F20 = buffer;
    buffer[0] = 0x30000009;
    D_00221F20[1] = (D_0021DAFC + 0xC0) & 0x0FFFFFFF;
    D_00221F20[2] = 0;
    D_00221F20[3] = 0x50000009;
    D_00221F20[4] = 0x30000025;
    D_00221F20[5] = (u32)D_0020C220;
    D_00221F20[6] = 0;
    D_00221F20[7] = 0x50000025;
    D_00221F20 += 8;
    D_00237100.count++;
    if (D_0023A900[0] != 0) {
        func_00449D20();
        buffer = D_00221F20;
    } else {
        func_00449E80();
        buffer = D_00221F20;
    }
    buffer[0] = 0x70000000;
    D_00221F20[1] = 0;
    D_00221F20 += 4;
}
