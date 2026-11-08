#include "common.h"

// Copy the 0x38 quadword to the owner and to the four entries of the list.
void func_L01_004F5970(u8 *p, u8 *list) {
    s32 i;
    u64 value;

    value = *(u64 *)(*(u8 **)(p + 0xB8) + 0x38);
    *(u64 *)(p + 0x38) = value;
    for (i = 0; i < 4; i++) {
        u8 *e = *(u8 **)(list + 0xD0 + i * 4);

        if (e != 0) {
            *(u64 *)(e + 0x38) = *(u64 *)(*(u8 **)(p + 0xB8) + 0x38);
        }
    }
}
