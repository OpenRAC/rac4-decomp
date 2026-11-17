#include "common.h"

extern s32 *func_006C1020(s32);
extern s32 (**func_L00_005DEBD0(s32, s32, s32))(s32, s32, s32, s32, s32, s32);
extern s32 func_L01_006C1180(s32);

// Finds the first index below 7 that passes the check and has a callback, runs it and returns whether it succeeded.
s32 func_L01_00586830(void) {
    s32 i;
    s32 result;
    s32 (**cb)(s32, s32, s32, s32, s32, s32);
    s32 *entry;

    result = 0;
    for (i = 0; i < 7; i++) {
        if (func_L01_006C1180(i) == 0) {
            continue;
        }
        cb = func_L00_005DEBD0(0xF6E, 0, 8);
        if (cb == 0) {
            continue;
        }
        if (*cb == 0) {
            continue;
        }
        entry = func_006C1020(i);
        result = (*cb)(entry[0], 0, 1, 0, 0, entry[1]);
        break;
    }
    return result != 0;
}
