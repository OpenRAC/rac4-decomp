/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 f4; } Ent;
typedef struct { Ent ents[8]; s32 f40; s32 count; } Obj;
extern void func_01EB6428(s32, void *);
void func_01EC0410(s32 ctx, Obj *o) {
    s32 i;
    for (i = 0; i < o->count; i++) {
        Ent *e = &o->ents[i];
        if (e->p != 0) {
            func_01EB6428(ctx, e->p);
            e->p = 0;
        }
    }
    o->count = 0;
    o->f40 = 0;
}
