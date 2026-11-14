/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x18]; s32 f18; char _p1c[0x14]; } E;
extern E D_001B7930[];
s32 func_01ED92C8(void) {
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_001B7930[i].f18 == 0) {
            return i;
        }
    }
    return 32;
}
