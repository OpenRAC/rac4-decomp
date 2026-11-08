/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EEE070(s32);

s32 func_01EEE028(s32 arg0)
{
    if (func_01EEE070(arg0)) {
        return 1;
    }
    if (arg0 >= 'A' && arg0 <= 'F') {
        return 1;
    }
    return arg0 >= 'a' && arg0 <= 'f';
}
