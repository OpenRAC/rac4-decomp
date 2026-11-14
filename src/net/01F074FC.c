/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct O O;
typedef struct { char _p0[0x18]; void (*f18)(O *, s32); } Vt;
struct O { Vt *vt; };
typedef struct { O *p; s32 x; } Slot;
void func_01F074FC(Slot *s) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (s[i].p != 0) {
            s[i].p->vt->f18(s[i].p, 1);
        }
    }
}
