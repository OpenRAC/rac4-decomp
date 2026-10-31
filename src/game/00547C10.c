#include "common.h"

extern s32 func_0045CB50(void);
extern s32 D_003DDE48[];

// Returns the index of the first zero word in the 10-entry record for arg0, or 9, or -1.
s32 func_00547C10(s32 arg0) {
    s32 i;
    s32 *p;

    if (func_0045CB50() != 0) {
        return 0x62;
    }
    p = (s32 *)((char *)D_003DDE48 + arg0 * 0x28);
    for (i = 0; i < 10; i++) {
        if (*p == 0) {
            return i - 1;
        }
        if (i == 9) {
            return 9;
        }
        p++;
    }
    return -1;
}
