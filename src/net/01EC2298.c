/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x48]; s32 f4C, f50, f54; } Obj;
s32 func_01EC2298(Obj *o, s32 *out) {
    if (o == 0) {
        return 0xD2F3;
    }
    if (o->f0 != 0xD) {
        return 0xD2F3;
    }
    if (out == 0) {
        return 2;
    }
    out[0] = o->f50;
    out[1] = o->f54;
    out[2] = o->f4C;
    return 0;
}
