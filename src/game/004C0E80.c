#include "common.h"

typedef struct {
    u8 f0[9];
    u8 f9;
    u8 fA[2];
} Type1;

extern Type1 D_001F87F0[];

s32 func_004C0E80(u32 arg0)
{
    s32 ids[4];
    s32 count = 0;
    s32 n = 0;
    s32 i;

    switch (arg0) {
    case 0:
        ids[n++] = 10;
        ids[n++] = 11;
        break;
    case 1:
        ids[n++] = 12;
        ids[n++] = 14;
        break;
    case 2:
        ids[n++] = 16;
        ids[n++] = 19;
        ids[n++] = 20;
        break;
    case 3:
        ids[n++] = 22;
        ids[n++] = 24;
        break;
    case 4:
        ids[n++] = 26;
        ids[n++] = 36;
        break;
    }

    for (i = 0; i < n; i++) {
        Type1 *p = &D_001F87F0[ids[i]];
        if (p->f9) {
            count++;
        }
    }
    return count;
}
