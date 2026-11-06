#include "common.h"

extern u8 D_003DF150[];

void *func_00548D28(s32 arg0, s32 arg1)
{
    if (arg1 < 3) {
        if (arg1 >= 0) {
            return D_003DF150 + arg0 * 0xB0;
        }
    }
    return D_003DF150 + arg0 * 0xB0;
}
