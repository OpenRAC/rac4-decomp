/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 id; u16 f2; } Id_4;
typedef struct { s32 f0; u32 n; Id_4 *ids; } Tbl_c;
extern s32 func_01EABF38(void **arg0);
extern s32 func_01EAC9A8(u32 arg0, Tbl_c *arg1);
extern s32 func_01EACA50(s32 arg0, s32 *arg1);
extern void func_01EACB58(s32 arg0, s32 arg1, s32 *arg2);
extern void func_01EACB98(s32 idx, void *p);

/* Sets entry arg0 of the table at arg2 to arg1 (0xFFFF clears it), creating the table when arg2 is NULL. */
s32 func_01EAC2A8(u32 arg0, u32 arg1, Tbl_c *arg2) {
    if (arg2 == 0) {
        func_01EABF38((void **)&arg2);
    }
    if (arg2->n == 0) {
        if (arg1 != 0xFFFF) {
            if (func_01EAC9A8(arg0, arg2) != 0) {
                return 0xDAC4;
            }
            func_01EACB58(arg0, arg1, (s32 *)arg2);
            return 0;
        }
        return 0;
    }
    if (arg0 >= arg2->n) {
        if (arg1 != 0xFFFF) {
            if (func_01EACA50(arg0, (s32 *)arg2) != 0) {
                return 0xDAC4;
            }
            func_01EACB58(arg0, arg1, (s32 *)arg2);
            return 0;
        }
        return 0;
    }
    if (arg2->ids[arg0].id == 0xFFFF) {
        if (arg1 != 0xFFFF) {
            func_01EACB58(arg0, arg1, (s32 *)arg2);
            return 0;
        }
        return 0;
    }
    if (arg1 == 0xFFFF) {
        func_01EACB98(arg0, arg2);
        return 0;
    }
    arg2->ids[arg0].id = arg1;
    return 0;
}
