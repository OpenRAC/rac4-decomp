/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x14]; s32 f18; } Type1;
extern u8 D_001B7930[];
s32 func_01ED9310(Type1 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if ((u8 *)arg0 < D_001B7930 && (u8 *)arg0 > D_001B7930 + 0x600) {
        return 0;
    }
    if (arg0->f18 == 0) {
        return 0;
    }
    return arg0->f0 < 2U;
}
