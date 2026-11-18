/* cflags: -mno-split-addresses */
#include "common.h"

#include "pal/global_002234A4.h"

typedef struct {
    u8 b[360];
} Block;

// Clears a byte in the record at +0x3C of the global and copies a 0x168-byte block into it.
void func_L00_00771360(Block *src) {
    u8 *base = *(u8 **)((u8 *)D_002234A4 + 0x3C);

    base[572] = 0;
    *(Block *)(base + 576) = *src;
}
