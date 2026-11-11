#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void *D_222D14;

/* Copy the 16 bytes of the record the object's member selects. */
u128 func_L01_0043C180(void *arg0) {
    void *entry = *(void **)((u8 *)arg0 + 0xAC);
    u8 *base = (u8 *)D_222D14 + ((*(s32 *)((u8 *)entry + 0x68)) << 8);

    return *(u128 *)(base + 0x10);
}
