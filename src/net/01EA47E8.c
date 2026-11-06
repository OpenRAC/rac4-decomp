/* cflags: @ee296 -O2 -G0 */
#include "common.h"

// Returns the indexed word when the table and index are valid.
s32 func_01EA47E8(s32 *table, u32 index) {
    if (table != NULL && index < 0x100U) return *(s32 *)((u8 *)table + (index << 2));
    return 0;
}
