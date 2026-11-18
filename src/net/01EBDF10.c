/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Reads two counters of a kind-0xD record (selected by arg2) into arg3/arg4 and stores their percentage, capped at 100, in arg5.
s32 func_01EBDF10(s32 arg0, u8 *arg1, s32 arg2, u32 *arg3, u32 *arg4, u32 *arg5) {
    if (arg0 == 0) {
        return 0xD2F2;
    }
    if (arg1 == NULL) {
        return 0xD2F3;
    }
    if (*(s32 *)arg1 != 0xD) {
        return 0xD2F3;
    }
    if (arg2 == 0) {
        if (arg3 != NULL) {
            *arg3 = *(u32 *)(arg1 + 0x14);
        }
        if (arg4 != NULL) {
            *arg4 = *(u32 *)(arg1 + 0x18);
        }
        if (arg5 != NULL) {
            *arg5 = *(u32 *)(arg1 + 0x18) * 100 / *(u32 *)(arg1 + 0x14);
            if (*arg5 > 100) {
                *arg5 = 100;
            }
        }
        return 0;
    }
    if (arg2 != 1) {
        return 2;
    }
    if (arg3 != NULL) {
        *arg3 = *(u32 *)(arg1 + 0x24);
    }
    if (arg4 != NULL) {
        *arg4 = *(u32 *)(arg1 + 0x28);
    }
    if (arg5 != NULL) {
        *arg5 = *(u32 *)(arg1 + 0x28) * 100 / *(u32 *)(arg1 + 0x24);
        if (*arg5 > 100) {
            *arg5 = 100;
        }
    }
    return 0;
}
