#include "common.h"

extern s32 func_L00_005C9F50(s32);
extern s32 D_004EEB68[];
extern u8 *D_004EEB90[];

// Returns field 8 of entry arg1 (12-byte entries) of table arg0, passed to a callee; 0 if out of range.
s32 func_L00_0077A790(u32 arg0, s32 arg1) {
    s32 idx = arg1;
    u8 *tab;

    if (arg0 < 9) {
        tab = D_004EEB90[arg0];
        if (idx < D_004EEB68[arg0]) {
            return func_L00_005C9F50(*(s32 *)(tab + idx * 12 + 8));
        }
    }
    return 0;
}
