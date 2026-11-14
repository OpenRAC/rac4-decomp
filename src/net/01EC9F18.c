/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[4]; s32 f4; char _p8[0xC]; char name[1]; } Node;
typedef struct { char _p0[8]; s32 f8; s32 fC; } Grp;
extern Grp *func_01EC8EA8(s32, s32);
extern Node *func_01EC98E8(s32);
extern s32 func_0011A8A0(const char *, const char *);
s32 func_01EC9F18(const char *name, s32 a, s32 b) {
    Grp *g;
    s32 i;
    if (name != 0) {
        g = func_01EC8EA8(a, b);
        if (g != 0) {
            for (i = 0; i < g->fC; i++) {
                s32 id = i + g->f8;
                Node *n = func_01EC98E8(id);
                if (n != 0 && n->f4 == 2 && func_0011A8A0(n->name, name) == 0) {
                    return id;
                }
            }
        }
    }
    return -1;
}
