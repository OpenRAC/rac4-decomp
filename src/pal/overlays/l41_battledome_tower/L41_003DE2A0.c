#include "common.h"
#include "pal/table_003982C8.h"

void func_L41_003DE2A0(void *arg0, s32 arg1)
{
    u32 index;
    u8 *state = *(u8 **)((u8 *)arg0 + 0xAC);
    if (*(s32 *)(state + 0x54) != arg1) {
        *(s32 *)(state + 0x54) = arg1;
        *(s32 *)(state + 0x5C) = 0;
        index = (u32)arg1;
        *(s32 *)(state + 0x64) = D_003982C8[index].a;
        *(s32 *)(state + 0x68) = D_003982C8[index].b;
        *(u16 *)((u8 *)arg0 + 0x36) = (u16)((*(u16 *)((u8 *)arg0 + 0x36) & 0x87FF) | ((u32)arg1 << 11));
    }
}
