/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } In;
typedef struct { In *f0; } Obj;
s32 func_01ED90A0(Obj *o) {
    if (o == 0) {
        return 0;
    }
    return o->f0->f4;
}
