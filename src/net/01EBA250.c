/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[4]; } B4;
typedef struct { char _p[0x14]; s32 f14; char _p18[0x38]; } Ent;
typedef struct { char _p0[0x184]; Ent *ents; char _p188[0x7C]; void (*cb)(s32, s32, s32); char _p208[0x10]; s32 f218; } Obj;
s32 func_01EBA250(Obj *o, u16 idx, B4 *src) {
    B4 s = *src;
    s32 k = o->f218;
    o->ents[idx].f14 = s.b[2];
    o->cb(idx, s.b[2], k);
    return 0;
}
