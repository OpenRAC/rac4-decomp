#include "common.h"

typedef struct { u8 pad[0x20]; s32 v; } Info;
typedef struct { u8 pad[0x34]; u16 flags; u8 pad36[0xAC - 0x36]; Info *info; } Obj;

/* With flag 0x20 at +0x34 set, word 0x20 of the object's info block (+0xAC), else 0; 0 for a null object. */
s32 func_L01_0058FE90(Obj *o) {
    if (o == 0) {
        return 0;
    }
    if (o->flags & 0x20) {
        return o->info->v;
    }
    return 0;
}
