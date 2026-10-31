#include "common.h"

extern void func_00453608(void *p, s32 v, s32 n);

// Zeroes the header of a record, clears its 0x2338-byte sub-table, and fills 25 slots with -1.
void func_004604F0(void *arg0) {
    s32 *var_s0;
    s32 var_v0;

    *(s32 *)((u8 *)arg0 + 0x0) = 0;
    *(s32 *)((u8 *)arg0 + 0x4) = 0;
    *(s32 *)((u8 *)arg0 + 0x8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    func_00453608((u8 *)arg0 + 0x10, 0, 0x2328);
    var_s0 = (s32 *)((u8 *)arg0 + 0x21D0);
    var_v0 = 0x18;
    do {
        *var_s0 = -1;
        var_v0 -= 1;
        var_s0 = (s32 *)((u8 *)var_s0 - 0x168);
    } while (var_v0 >= 0);
}
