/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00167EEC[];

/* Copy field 8 of arg0 into the first list node whose id matches arg0's. */
s32 func_01E9DA40(s32 *arg0) {
    char *p;
    s32 v;

    for (p = (char *)D_00167EEC[0]; p != 0; ) {
        if (*(s32 *)(p + 0x10) == arg0[1]) {
            v = arg0[2];
            *(s32 *)(p + 0x8) = v;
            if (v == 0) {
                *(s32 *)(p + 0xC) = 1;
            }
            p = 0;
        } else {
            p = *(char **)(p + 0x3C);
        }
    }
    return 0;
}
