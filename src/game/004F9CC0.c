#include "common.h"
extern u64 D_0020E280[];
extern int D_0021DF1C;
/* Build the fixed command record and set its byte count. */
void func_004F9CC0(void)
{
    D_0020E280[0] = 0x1000000000000004ULL;
    D_0020E280[1] = 14;
    D_0020E280[2] = 0;
    D_0020E280[3] = 63;
    D_0020E280[4] = 0xA0000000A0ULL;
    D_0020E280[5] = 25;
    D_0020E280[6] = 96;
    D_0020E280[7] = 21;
    D_0020E280[8] = 5;
    D_0020E280[9] = 9;
    D_0021DF1C = 80;
}
