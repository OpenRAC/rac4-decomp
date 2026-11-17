/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_222C14;

/* Append a record to the table entry for slot arg1: bump its counter and write the new record. */
void func_L01_005A1320(s32 arg0, s32 arg1, s32 arg2) {
    u8 *rec;
    u8 *slot;

    if (arg0 != 0) {
        rec = (u8 *)D_222C14 + arg1 * 0xE0;
        rec[4]++;
        slot = rec + (((rec[4] & 0xFF) * 8) - 8);
        *(s32 *)slot = arg0;
        slot[5] = arg2;
        *(u16 *)(slot + 6) = 0;
    }
}
