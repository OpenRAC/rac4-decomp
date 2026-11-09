/* cflags: -mno-split-addresses */
#include "common.h"

s32 func_01EA9718(void *);

s32 func_01E9DD68(void *p) {
    return (func_01EA9718(p) == 0) ? 0 : -1;
}
