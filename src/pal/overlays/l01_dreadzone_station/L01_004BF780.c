#include "common.h"

extern u8 D_003AAED8[];
extern u8 D_0024AE20[];
extern s32 func_L01_004BF6E8(void *object);
extern s32 func_0045EB78(s32 value);

/* Preserve separate native row, mask and comparison bases across the calls. */
s32 func_L01_004BF780(void *object)
{
    u8 *inner = *(u8 **)((u8 *)object + 0xAC);
    u32 table;
    u32 global;
    u32 masks;
    s32 index;
    if (func_L01_004BF6E8(object) == 0) return 0;
    table = (u32)D_003AAED8;
    global = (u32)D_0024AE20;
    masks = table + 0x14;
    index = 0;
    do {
        u32 address = index * 4;
        s32 value;
        address += *(u32 *)(inner + 0x380) * 0x18;
        address += table;
        value = *(s32 *)address;
        if (value != -1 && *(s32 *)(global + 0xC) == func_0045EB78(value)) {
            u32 maskOffset = *(u32 *)(inner + 0x380) * 0x18;
            s32 bits = *(s32 *)(maskOffset + masks);
            if ((bits >> index) & 1) return 1;
        }
        index++;
    } while (index < 3);
    return 0;
}
