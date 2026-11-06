#include "common.h"

extern u8 D_003DF190[];

void *func_0054A290(s32 arg0, s32 arg1)
{
    if (arg1 < 3) {
        if (arg1 >= 0) {
            return D_003DF190 + arg0 * 0xB0;
        }
    }
    return D_003DF190 + arg0 * 0xB0;
}
