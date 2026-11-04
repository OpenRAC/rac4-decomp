#include "common.h"

s32 D_00220798 = 0;
extern char *D_00221F20;

/* Append a command packet, prefixing its setup words when needed. */
void func_004E88B8(s32 command, u64 value, s32 unused)
{
    if (!D_00220798) {
        *(u32 *)(D_00221F20 + 0) = 0x10000002u;
        *(u32 *)(D_00221F20 + 4) = 0;
        *(u32 *)(D_00221F20 + 8) = 0;
        *(u32 *)(D_00221F20 + 12) = 0x50000002u;
        *(u32 *)(D_00221F20 + 16) = 0x8001;
        *(u32 *)(D_00221F20 + 20) = 0x10000000;
        *(u32 *)(D_00221F20 + 24) = 14;
        *(u32 *)(D_00221F20 + 28) = 0;
        D_00221F20 += 32;
    }
    *(u64 *)D_00221F20 = value;
    *(s32 *)(D_00221F20 + 8) = command;
    *(u32 *)(D_00221F20 + 12) = 0;
    D_00221F20 += 16;
}
