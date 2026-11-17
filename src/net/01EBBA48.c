/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 h; s32 timer[2]; } Ent_c;
typedef struct { s32 f0; Ent_c ents[32]; } Ctx_184;
extern s32 func_01EAB2A0(s32 *, u32 *);
extern s32 func_01EBE4D8(s32, s32);
s32 func_01EBBA48(Ctx_184 *c) {
    u32 t;
    u32 i;
    for (i = 0; i < 32; i++) {
        if (c->ents[i].h != 0) {
            func_01EAB2A0(c->ents[i].timer, &t);
            if (t > 7500) {
                func_01EBE4D8(c->f0, c->ents[i].h);
                c->ents[i].h = 0;
            }
        }
    }
    return 0;
}
