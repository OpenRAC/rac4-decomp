/* Not matching yet: SIZE ours 120 / retail 128 (tools/try_func.py func_01EB8B60 --diff). Not part of the build. */
#include "common.h"

// True when the cell at row `row`, column `col` is in use.
s32 func_01EB8B60(u8 *p, u8 row, u16 col, s32 *out) {
    u32 *table;
    u32 *cells;
    s32 r = 2;

    if (out != 0) {
        *out = 0;
        if (p != 0 && row < *(u32 *)(p + 0x1D8)) {
            table = *(u32 **)(p + 0x188);
            r = 3;
            if (table != 0) {
                r = 2;
                if (col < *(u16 *)(p + 0x19C)) {
                    cells = *(u32 **)((u8 *)table + row * 0x18);
                    if (cells[col] != 0) {
                        *out = 1;
                    }
                    r = 0;
                }
            }
        }
    }
    return r;
}
