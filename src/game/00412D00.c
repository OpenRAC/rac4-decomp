/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4; u64 *f8; } Obj;
s32 func_00412D00(s32 i, Obj *o) {
    while (o->f8[i] == 0 && i > 0) {
        i--;
    }
    o->f4 = i + 1;
    return 0;
}
