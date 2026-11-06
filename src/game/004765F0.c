#include "common.h"

typedef struct { u8 pad[0x1C]; s32 v; } Info;
typedef struct { u8 pad[0x34]; u16 flags; u8 pad36[0xAC - 0x36]; Info *info; } Obj;

/* As func_004765B0, for word 0x1C of the info block. */
s32 func_004765F0(Obj *o) {
    if (o == 0) {
        return 0;
    }
    if (o->info == 0) {
        return 0;
    }
    if (o->flags & 0x20) {
        return o->info->v;
    }
    return 0;
}
