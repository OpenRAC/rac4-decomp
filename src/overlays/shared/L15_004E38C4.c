#include "common.h"

/* Bit 1 of the byte 0x55 into the object reached through the member at 0x108. */
s32 func_L15_004E38C4(s32 arg0, void *arg1) {
    return (*(u8 *)((*(u8 **)((u8 *)arg1 + 0x108)) + 0x55)) & 2;
}
