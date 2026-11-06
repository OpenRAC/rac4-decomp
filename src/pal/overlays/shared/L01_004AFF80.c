#include "common.h"

/* Copies the linked enable bit into the local halfword flags. */
s32 func_L01_004AFF80(void *arg0)
{
    s32 result;

    result = *(s32 *)((u8 *)arg0 + 0xB8);
    if (*(u32 *)((u8 *)arg0 + 0xB8)) {
        result = *(u16 *)(result + 0x34) & 1;
        if (result) {
            result = *(u16 *)((u8 *)arg0 + 0x34) | 0x41;
            *(u16 *)((u8 *)arg0 + 0x34) = result;
        }
    }
    return result;
}
