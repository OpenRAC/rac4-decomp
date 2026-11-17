/* cflags: -mno-split-addresses */
#include "common.h"

extern u8 *D_002233A4[];

typedef struct {
    u8 b[0x148];
} Block;

// Clears a byte in the record at +0x3C of the global and copies a 0x148-byte block into it.
void func_L00_0076C130(Block *src) {
    u8 *base = *(u8 **)(D_002233A4[0] + 0x3C);

    base[0xF0] = 0;
    *(Block *)(base + 0xF4) = *src;
}
