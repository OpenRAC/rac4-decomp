/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x10]; s32 f14; char _p18[0xC]; s32 f24; } Ctx;
s32 func_01EBDE78(s32 o, Ctx *c, s32 which, s32 *out) {
    *out = 0;
    if (o == 0) {
        return 0xD2F2;
    }
    if (c == 0) {
        return 0xD2F3;
    }
    if (c->f0 != 0xD) {
        return 0xD2F3;
    }
    if (which == 0) {
        *out = c->f14;
        return 0;
    }
    if (which == 1) {
        *out = c->f24;
        return 0;
    }
    return 2;
}
