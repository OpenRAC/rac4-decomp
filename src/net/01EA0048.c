/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 _p0[8]; s32 f20; } Ent_24;
typedef struct { Ent_24 *ents[256]; Ent_24 *self; char _p404[0x5C]; s32 count; } Obj_464;
typedef struct { u32 bits[8]; s32 lo; s32 hi; } Bits_28;
typedef struct { s32 n; Bits_28 b; } Out_2c;
extern void *func_0011A518(void *, s32, s32);
extern s32 func_01E9FFD8(Bits_28 *, s32);
s32 func_01EA0048(Obj_464 *o, Out_2c *out) {
    s32 i;
    if (o == 0) {
        return 0x17;
    }
    if (out == 0) {
        return 0x17;
    }
    func_0011A518(out, 0, sizeof(*out));
    out->n = 0x100;
    out->b.hi = o->count;
    for (i = 0; i < o->count; i++) {
        Ent_24 *e = o->ents[i];
        if (e != 0 && e != o->self && e->f20 != 0) {
            func_01E9FFD8(&out->b, i);
        }
    }
    return 0;
}
