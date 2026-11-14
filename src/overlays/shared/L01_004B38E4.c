#include "common.h"

typedef int u128 __attribute__((mode(TI)));

// Return the 128-bit value at offset 0x310 of the third argument.
u128 func_L01_004B38E4(void *arg0, void *arg1, void *arg2) {
    return *(u128 *)((u8 *)arg2 + 0x310);
}
