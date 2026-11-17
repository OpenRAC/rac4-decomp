/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x2C]; } E;
extern E D_001B7948[];
s32 func_01ED97B8(u32 mask, s32 i) {
    for (; i < 32; i++) {
        if (D_001B7948[i].f0 != 0 && (mask & (1 << i))) {
            return i;
        }
    }
    return 32;
}
