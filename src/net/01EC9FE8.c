/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[4]; s32 f4; } Node;
typedef struct { char _p0[8]; s32 f8; s32 fC; } Grp;
typedef struct { char _p0[0x404]; s32 f404; } Sess;
extern Sess *D_001B7390;
extern Grp *func_01EC8EA8(Sess *, s32);
extern Node *func_01EC98E8(s32);
s32 func_01EC9FE8(void) {
    Sess *s = D_001B7390;
    Grp *g;
    s32 i;
    if (s == 0) {
        return -1;
    }
    g = func_01EC8EA8(s, s->f404);
    if (g == 0) {
        return -1;
    }
    for (i = 0; i < g->fC; i++) {
        s32 id = i + g->f8;
        Node *n = func_01EC98E8(id);
        if (n != 0 && n->f4 != 2) {
            return id;
        }
    }
    return -1;
}
