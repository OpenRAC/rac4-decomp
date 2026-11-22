/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { s32 pad[11]; s32 f2C; } Sub;
typedef struct { u8 pad[0x34]; u16 flags; u8 pad2[0x76]; Sub *sub; } Obj;

s32 func_L00_005F1AE8(Obj *arg0) {
    if (arg0 == 0 || arg0->sub == 0) {
        return 0;
    }
    if (arg0->flags & 0x20) {
        return arg0->sub->f2C;
    }
    return 0;
}
