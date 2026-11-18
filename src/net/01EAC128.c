/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 id; u16 f2; } Id_4;
typedef struct { s32 f0; u32 n; Id_4 *ids; } Tbl_c;
extern void func_01EABF38(Tbl_c **arg0);
extern s32 func_01EAC9A8(u32 arg0, Tbl_c *arg1);
extern s32 func_01EACA50(u32 arg0, Tbl_c *arg1);
extern void func_01EACB58(s32 arg0, s32 arg1, Tbl_c *arg2);

/* Looks up arg0 in the table at arg2 into *arg1, falling back to the helper calls when the entry is empty. */
s32 func_01EAC128(u32 arg0, u32 *arg1, Tbl_c *arg2) {
    if (arg2 == 0) {
        func_01EABF38(&arg2);
    }
    if (*arg1 == 0xFFFF) {
        return 0xDAC2;
    }
    if (arg2->n == 0) {
        if (func_01EAC9A8(arg0, arg2) != 0) {
            return 0xDAC4;
        }
        func_01EACB58(arg0, *arg1, arg2);
        return 0;
    }
    if (arg0 >= arg2->n) {
        if (func_01EACA50(arg0, arg2) != 0) {
            return 0xDAC4;
        }
        func_01EACB58(arg0, *arg1, arg2);
        return 0;
    }
    if (arg2->ids[arg0].id == 0xFFFF) {
        func_01EACB58(arg0, *arg1, arg2);
        return 0;
    }
    *arg1 = arg2->ids[arg0].id;
    return 0xDAC2;
}
