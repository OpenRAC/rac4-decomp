/* cflags: -mno-split-addresses */
#include "common.h"

void *func_00500AE8(s32, s32);

/* Looks up arg1 in the table at (*arg0 + 0x1CC); arg1 passes through in $a1. */
void *func_005005E8(s32 *arg0, s32 arg1) {
    return func_00500AE8(*arg0 + 0x1CC, arg1);
}
