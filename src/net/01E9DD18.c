/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_01EA95C0(void *);

s32 func_01E9DD18(void *p) {
    return (func_01EA95C0(p) == 0) ? 0 : -1;
}
