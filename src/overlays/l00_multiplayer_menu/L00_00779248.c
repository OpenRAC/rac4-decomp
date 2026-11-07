/* cflags: -G0 */
#include "common.h"

extern u8 D_1723C1;

// Reset the selection state, seeded from D_1723C1.
void func_L00_00779248(u8 *p) {
    *(u8 *)(p + 0x11C) = D_1723C1;
    *(u8 *)(p + 0x11D) = 0;
    *(u8 *)(p + 0x11E) = 0;
    *(u8 *)(p + 0x11F) = 0;
    *(u8 *)(p + 0x120) = 0;
    *(u8 *)(p + 0x121) = 0;
    *(u8 *)(p + 0x154) = 0;
    *(u8 *)(p + 0x174) = 0;
    *(u8 *)(p + 0x175) = 0;
    *(u8 *)(p + 0x176) = 0;
}
