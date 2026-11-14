#include "common.h"

/* If the record at +0xB8 is set and its +0x34 halfword has bit 0, sets bits 0x41 in this record's +0x34 halfword. */
void func_L05_0048EB88(u8 *a0) {
    u8 *v;

    v = *(u8 **)(a0 + 0xB8);
    if (v != 0 && (*(u16 *)(v + 0x34) & 1) != 0) {
        *(u16 *)(a0 + 0x34) = *(u16 *)(a0 + 0x34) | 0x41;
    }
}
