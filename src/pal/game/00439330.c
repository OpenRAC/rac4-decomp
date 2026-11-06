#include "common.h"

typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
} Entry;

extern Entry D_003D6498[][8];

s32 func_00439330(Entry *src, u8 *state)
{
    s32 index = 0;
    s32 count;
    s32 i;
    s32 j;

    if (state) {
        if (state[0x558] == 0xFF)
            return 0;
        index = state[0x54C] * 4 + state[0x558];
    }

    for (count = 0; count < 8 && src[count].f0 != 0xFF; count++) {
    }

    for (i = 0, j = 0; j < 8 && i < count; j++) {
        if (D_003D6498[index][j].f0 == 0)
            i++;
    }
    if (i != count)
        return -1;

    for (i = 0; i < count; i++) {
        for (j = 0; j < 8 && D_003D6498[index][j].f0 != 0; j++) {
        }
        if (j < 8) {
            D_003D6498[index][j].f0 = src[i].f0;
            D_003D6498[index][j].f1 = src[i].f1;
            D_003D6498[index][j].f2 = src[i].f2;
            D_003D6498[index][j].f3 = src[i].f3;
            D_003D6498[index][j].f4 = src[i].f4;
            D_003D6498[index][j].f6 = src[i].f6;
            D_003D6498[index][j].f8 = src[i].f8;
            D_003D6498[index][j].fA = src[i].fA;
            D_003D6498[index][j].fC = src[i].fC;
            D_003D6498[index][j].fE = src[i].fE - src[i].fF;
            D_003D6498[index][j].fF = src[i].fF;
            if ((s16)D_003D6498[index][j].fA + (s16)D_003D6498[index][j].fC == 0)
                D_003D6498[index][j].fA++;
        }
    }
    return j;
}
