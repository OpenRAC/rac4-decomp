/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x468]; s32 f468; } Obj;
typedef struct { char _p0[0xE0]; void (*fE0)(Obj *, u16); char _pe4[0x40]; s32 f124; } Ctx;
extern Ctx *D_00167F38;
void func_01EA5700(u16 a0, s32 a1, Obj *o) {
    Ctx *c;
    if (o->f468 != 2) {
        return;
    }
    c = D_00167F38;
    if (c == 0 || a1 == 0 || c->f124 == 0 || o == 0) {
        return;
    }
    c->fE0(o, a0);
}
