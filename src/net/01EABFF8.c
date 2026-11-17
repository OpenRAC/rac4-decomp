/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 id; u16 f2; } Id_4;
typedef struct { s32 f0; u32 n; Id_4 *ids; } Tbl_c;
extern void func_01EABF38(Tbl_c **);
extern void func_01EACB98(u32, Tbl_c *);
void func_01EABFF8(u32 id, Tbl_c *t) {
    u32 i;
    if (t == 0) {
        func_01EABF38(&t);
    }
    if (id == 0xFFFF) {
        return;
    }
    if (t->f0 == 0) {
        return;
    }
    for (i = 0; i < t->n; i++) {
        if (t->ids[i].id == id) {
            func_01EACB98(i, t);
        }
    }
}
