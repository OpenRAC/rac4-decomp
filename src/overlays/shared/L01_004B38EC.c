#include "common.h"

typedef int u128 __attribute__((mode(TI)));

// Returns the 128-bit value at offset 0x630 of the object in $a2.
u128 func_L01_004B38EC(void *a0, void *a1, u8 *a2) {
    return *(u128 *)(a2 + 0x630);
}
