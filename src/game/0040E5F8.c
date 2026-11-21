/* cflags: @ee296 -O2 -G0 */
#include "common.h"
typedef struct { s32 f; s32 pad[4]; } E;
typedef struct Obj Obj;
typedef struct { s32 (*fn)(Obj *, s8 *, s32); } VT;
struct Obj { VT *vt; };
typedef struct { u8 pad[0x1C]; Obj *o; } Ctx;
extern void func_0040A9D0(u32 *, E *);
extern void func_0040A810(Ctx *, s32, s32, void *, s32);
extern s32 D_003CD3E0;
void func_0040E5F8(Ctx *c, s32 a1, E *e) {
    u32 n;
    u32 i;
    s8 msg[2];
    func_0040A9D0(&n, e);
    i = 0;
    if (n) {
        if (!(e->f & 0x4000)) {
            E *p = e;
            do {
                i++;
                p++;
                if (i >= n) goto no;
            } while (!(p->f & 0x4000));
        }
        if (i < n) {
            msg[0] = a1;
            msg[1] = 0x80;
            c->o->vt->fn(c->o, msg, 2);
            return;
        }
    }
no:
    func_0040A810(c, a1, 0, &D_003CD3E0, 0);
}
