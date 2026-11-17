#include "common.h"

typedef struct { s32 a; s32 b; s32 c; } Type1;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_30B5B0[];

/* Fills a table of 0xC-byte entries with defaults and bumps some entries. */
s32 func_004BED98(void) {
    Type1 *p;
    s32 i;
    s32 n;
    s32 count;

    count = 0xF;
    n = 0xB;
    D_30B5B0[34] = n;
    D_30B5B0[1] = 0;
    D_30B5B0[2] = 1;
    D_30B5B0[4] = 2;
    D_30B5B0[5] = 0;
    D_30B5B0[7] = 4;
    D_30B5B0[8] = 0;
    D_30B5B0[10] = 5;
    D_30B5B0[11] = 0;
    D_30B5B0[13] = 1;
    D_30B5B0[14] = 1;
    D_30B5B0[16] = 6;
    D_30B5B0[17] = 0;
    D_30B5B0[19] = 8;
    D_30B5B0[20] = 0;
    D_30B5B0[22] = 2;
    D_30B5B0[23] = 1;
    D_30B5B0[25] = 7;
    D_30B5B0[26] = 0;
    D_30B5B0[28] = 0xA;
    D_30B5B0[29] = 0;
    D_30B5B0[31] = 3;
    D_30B5B0[32] = 1;
    D_30B5B0[35] = 0;
    D_30B5B0[37] = 0xD;
    D_30B5B0[38] = 0;
    D_30B5B0[40] = 4;
    D_30B5B0[41] = 1;
    n = 0xE;
    D_30B5B0[43] = n;
    D_30B5B0[44] = 0;
    D_30B5B0[46] = count;
    D_30B5B0[47] = 0;
    if (D_0021EDD4 == 0) {
        if (D_0021EDD8 == 1) {
            p = (Type1 *)(D_30B5B0 + 1);
            for (i = count; i >= 0; i--) {
                if (p->b == 0) {
                    p->a += 0x14;
                }
                p++;
            }
        }
    }
    return count;
}
