/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern s32 D_001AF918[];

s32 func_01EA4680(s32 arg0, s32 arg1)
{
    if (D_001AF918[arg0] == 0) {
        D_001AF918[arg0] = arg1;
        return 0;
    }
    return 0x17;
}
