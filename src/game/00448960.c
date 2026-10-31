#include "common.h"

extern u8 D_206A48[];

/* Clears the hardware registers at 0x12000000 and copies D_206A48 into the 0x12000020 to 0x120000A0 group. */
void func_00448960(void) {
    s64 t0;
    s64 v1;

    *(volatile s64 *)0x120000E0 = 0;
    *(volatile s64 *)0x12000000 = 0xFFA1;
    *(volatile s64 *)0x12000020 = *(s64 *)(D_206A48 + 0);
    t0 = *(s64 *)(D_206A48 + 8);
    *(volatile s64 *)0x12000070 = t0;
    *(volatile s64 *)0x12000090 = t0;
    v1 = *(s64 *)(D_206A48 + 0x10);
    *(volatile s64 *)0x12000080 = v1;
    *(volatile s64 *)0x120000A0 = v1;
    *(volatile s64 *)0x120000D0 = 0;
}
