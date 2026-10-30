#include "common.h"

/* Stores the 16-byte value at arg3 into the entry of each slot in arg1's table, offset by arg2 << 6. */
typedef int u128 __attribute__((mode(TI)));

void func_00452698(s32 arg0, u8 *arg1, s32 arg2, u128 *arg3) {
    s32 i;
    s32 *p;

    i = 0;
    if (*(s32 *)(arg1 + 0xA4) > 0) {
        arg2 = arg2 << 6;
        p = (s32 *)(arg1 + 0x10);
        do {
            i++;
            *(u128 *)(arg2 + *p + 0x10) = *arg3;
            p++;
        } while (i < *(s32 *)(arg1 + 0xA4));
    }
}
