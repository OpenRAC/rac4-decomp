#include "common.h"

extern s16 D_004EB818[];
/* Return 1 when no entry of the 5-column table equals the value. */
u8 func_L00_0073FD28(s32 arg0) {
    s32 found = 1;
    s32 i = 0;
    s32 j = 0;
    s16 *p;
    do {
        if (found) {
            p = D_004EB818 + i;
            do {
                j++;
                if (arg0 == *p) found = 0;
                p += 5;
            } while (found && j < 0x35);
        }
        i++;
        if (!found) break;
        j = 0;
    } while (i < 5);
    return found ^ 1;
}
