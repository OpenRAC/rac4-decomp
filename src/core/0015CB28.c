#include "common.h"

extern u8 D_00172160[];

/* Returns 1 when arg0 is one of the n words at the pointer stored at +0xC0 of the table at D_00172160 (n is the word the pointer at +0xBC leads to), else 0. */
s32 func_0015CB28(s32 arg0) {
    u8 *g = D_00172160;
    s32 *cnt;
    s32 *tbl;
    s32 i;

    cnt = *(s32 **)(g + 0xBC);
    if (cnt != 0) {
        tbl = *(s32 **)(g + 0xC0);
        if (tbl != 0) {
            for (i = 0; i < *cnt; i++) {
                if (tbl[i] == arg0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
