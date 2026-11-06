#include "common.h"
extern u64 D_0020E300[];
extern int D_0021DFA4;
/* Build the fixed command record and set its byte count. */
void func_004FAD40(void)
{
    D_0020E300[0] = 0x1000000000000004ULL;
    D_0020E300[1] = 14;
    D_0020E300[2] = 0;
    D_0020E300[3] = 63;
    D_0020E300[4] = 0xA0000000A0ULL;
    D_0020E300[5] = 25;
    D_0020E300[6] = 96;
    D_0020E300[7] = 21;
    D_0020E300[8] = 5;
    D_0020E300[9] = 9;
    D_0021DFA4 = 80;
}
