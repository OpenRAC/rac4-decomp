/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 id; u16 f2; } Id_4;
typedef struct { s32 f0; u32 n; Id_4 *ids; } Tbl_c;
extern void func_01EABF38(Tbl_c **);
void func_01EAC0A0(u32 idx, u32 *out, Tbl_c *t) {
    u32 v;
    if (t == 0) {
        func_01EABF38(&t);
    }
    if (t->f0 != 0 && idx < t->n) {
        if (t->ids[idx].id != 0xFFFF) {
            *out = t->ids[idx].id;
            return;
        }
    }
    *out = 0xFFFF;
}
