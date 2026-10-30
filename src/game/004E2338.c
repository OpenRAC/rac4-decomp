#include "common.h"

/* Looks up an object by id and, if found, flags it and copies a 16-byte value into it. */
extern void *func_00453EB0(s16);
typedef int u128 __attribute__((mode(TI)));

s32 func_004E2338(s16 arg0, u128 *arg1) {
    u8 *temp_v0;

    temp_v0 = func_00453EB0(arg0);
    if (temp_v0 != NULL) {
        *(s32 *)(temp_v0 + 0x54) = *(s32 *)(temp_v0 + 0x54) | 0x40;
        *(u128 *)(temp_v0 + 0x30) = *arg1;
    }
    return 1;
}
