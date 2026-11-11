#include "common.h"

typedef int u128 __attribute__((mode(TI)));

/* Store the 128-bit argument and a copy of arg2 into the object. */
void func_L01_0048AD68(void *arg0, u128 arg1, u128 *arg2) {
    u128 tmp[1];

    tmp[0] = *arg2;
    *(u128 *)((u8 *)arg0 + 0xD70) = arg1;
    *(u128 *)((u8 *)arg0 + 0xD80) = tmp[0];
}
