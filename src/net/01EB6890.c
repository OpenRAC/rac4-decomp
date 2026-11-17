/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[8]; u32 unit; char _pC[4]; u32 base; u8 *map; } Bm_18;
void func_01EB6890(Bm_18 *b, u32 addr) {
    u32 off;
    u32 idx;
    u32 n;
    u32 i;
    if (b == 0) {
        return;
    }
    if (addr == 0) {
        return;
    }
    off = addr - b->base;
    if (off % b->unit != 0) {
        return;
    }
    idx = off / b->unit;
    n = b->map[idx] & 0x7F;
    for (i = 0; i < n; i++) {
        b->map[idx + i] = 0;
    }
}
