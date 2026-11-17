/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

void func_0011A518(void *, s32, s32);
s32 func_01EA9550(void **, s32);
s32 func_01EABF38(void **arg0) {
    if (*arg0 == NULL) {
        if (func_01EA9550(arg0, 0xC) != 0) {
            return 0xDAC4;
        }
        func_0011A518(*arg0, 0, 0xC);
        return 0;
    }
    return 0xDAC5;
}
