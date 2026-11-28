#include "pal/l00_roster_001E0DF8.h"

void func_L00_00780220(s32 *sum, s32 *occupied, s32 *id, s32 *found) {
    s32 i;
    s32 none;
    s32 j;

    i = 0;
    none = -1;
    do {
        if (D_001E0DF8.f4B0[i] != 0 && *id == none) {
            *id = i;
        }
        if (D_001E0DF8.slots[i].count > 0) {
            *sum += D_001E0DF8.slots[i].count;
            *occupied += 1;
        }
        i += 1;
    } while (i < 10);
    i = 0;
    do {
        j = 0;
        while (j < D_001E0DF8.slots[i].count) {
            if (D_001E0DF8.slots[i].ids[j] == *id) {
                *found = j;
                break;
            }
            j += 1;
        }
        i += 1;
    } while (i < 10);
}
