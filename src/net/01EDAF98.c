/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 v; char _p2[6]; } Ent;
typedef struct { char _p0[8]; u16 n; char _pa[2]; Ent e[32]; } Tab;
u16 func_01EDAF98(Tab *t, u16 i) {
    if (t == 0) {
        return 0xFFFF;
    }
    if (i >= 0x20) {
        return 0xFFFF;
    }
    if (i >= t->n) {
        return 0xFFFF;
    }
    return t->e[i].v;
}
