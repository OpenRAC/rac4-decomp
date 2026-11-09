#include "common.h"

void func_004496E0(void);
void func_00449840(void);
extern s32 *D_00221E20;
extern s32 D_0021DA7C;
extern s32 D_0020C1A0[];
extern s32 D_00237000[];
extern s32 D_0023A800[];

void func_00488A98(s32 *packet)
{
    D_00221E20 = packet;
    packet[0] = 0x30000009;
    D_00221E20[1] = (D_0021DA7C + 0xC0) & 0x0FFFFFFF;
    D_00221E20[2] = 0;
    D_00221E20[3] = 0x50000009;
    D_00221E20[4] = 0x30000025;
    D_00221E20[5] = (s32)D_0020C1A0;
    D_00221E20[6] = 0;
    D_00221E20[7] = 0x50000025;
    D_00221E20 += 8;
    D_00237000[29]++;
    if (D_0023A800[0] != 0) {
        func_004496E0();
    } else {
        func_00449840();
    }
    D_00221E20[0] = 0x70000000;
    D_00221E20[1] = 0;
    D_00221E20 += 4;
}
