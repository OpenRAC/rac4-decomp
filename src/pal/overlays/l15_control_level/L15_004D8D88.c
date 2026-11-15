/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef struct { s32 value[5]; } WordTable;
extern WordTable D_003B1700;
extern WordTable D_003B1718;
s32 func_L15_004D8D88(s32 input)
{
    WordTable masks = D_003B1700;
    WordTable shifts = D_003B1718;
    s32 result = 0;
    if (input & masks.value[4]) {
        input >>= shifts.value[4];
        result = shifts.value[4];
    }
    if (input & masks.value[3]) {
        input >>= shifts.value[3];
        result |= shifts.value[3];
    }
    if (input & masks.value[2]) {
        input >>= shifts.value[2];
        result |= shifts.value[2];
    }
    if (input & masks.value[1]) {
        input >>= shifts.value[1];
        result |= shifts.value[1];
    }
    if (input & masks.value[0]) {
        result |= shifts.value[0];
    }
    return result;
}
