#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern u8 *D_0021DFE8;

/* Counts distinct values among the active entries' 0xFA-table bytes. */
s32 func_L00_007575D8(void) {
    u8 seen[10];
    s32 count;
    s32 i;
    u8 *p;
    u8 *tbl;

    count = 0;
    func_0011A518(seen, 0, 10);
    tbl = D_0021DFE8 + 0xFA;
    p = D_0021DFE8;
    for (i = 0; i < 10; i++, p += 0x10) {
        if (*p == 0) {
            continue;
        }
        if (seen[tbl[i]] != 0) {
            continue;
        }
        seen[tbl[i]] = 1;
        count++;
    }
    return count;
}
