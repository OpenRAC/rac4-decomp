/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } Ev;
typedef void (*Cb)(s32, s32, s32, Ev *, s32, s32, s32, s32);
typedef struct { char _p0[8]; s32 f8; char _pC[0xC]; Cb f18; s32 f1C; char _p20[0x10]; } Ent;
extern Ent D_001B7930[32];
extern void *func_0011A518(void *, s32, u32);
void func_01ED9358(void) {
    Ev ev;
    Ent *e;
    s32 i;
    ev.f0 = -0x3A9;
    ev.f4 = 200;
    ev.f8 = 0;
    e = D_001B7930;
    for (i = 0; i < 32; i++, e++) {
        if (e->f18 != 0) {
            e->f18(1, ev.f0, e->f8, &ev, 0, 0, 0, e->f1C);
            func_0011A518(e, 0, sizeof(Ent));
        }
    }
}
