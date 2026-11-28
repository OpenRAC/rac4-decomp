#include "pal/object_data.h"

typedef struct {
    s32 w[15];
} FlagBlock;

static FlagBlock D_L05_003ADF88 = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

/* Copies the 15 flags, clears the bits selected by vars+0x558, and packs the rest into +0x74. */
void func_L05_004DD2B8(u8 *arg0) {
    FlagBlock tmp;
    s32 idx;
    s32 i;
    s32 mask;

    tmp = D_L05_003ADF88;
    idx = *(s32 *)((u8 *)((PalObject *)arg0)->data + 0x558);
    switch (idx) {
    case 0:
        break;
    case 1:
        tmp.w[14] = 0;
        break;
    case 2:
        tmp.w[14] = 0;
        tmp.w[12] = 0;
        tmp.w[13] = 0;
        break;
    case 3:
        tmp.w[14] = 0;
        tmp.w[12] = 0;
        tmp.w[13] = 0;
        tmp.w[6] = 0;
        tmp.w[7] = 0;
        break;
    case 4:
        tmp.w[14] = 0;
        tmp.w[12] = 0;
        tmp.w[13] = 0;
        tmp.w[6] = 0;
        tmp.w[7] = 0;
        tmp.w[10] = 0;
        break;
    case 5:
        tmp.w[14] = 0;
        tmp.w[12] = 0;
        tmp.w[13] = 0;
        tmp.w[6] = 0;
        tmp.w[7] = 0;
        tmp.w[10] = 0;
        tmp.w[8] = 0;
        tmp.w[9] = 0;
        break;
    }
    mask = 0;
    for (i = 0; i < 15; i++) {
        if (tmp.w[i] != 0) {
            mask |= 1 << i;
        }
    }
    *(u16 *)(arg0 + 0x74) = (u16)mask;
}
