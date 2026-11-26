/* Not matching yet: BYTES 1/136 (tools/try_func.py func_01ECA098 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x100]; u32 f100; } Ctx;
typedef struct { char _p0[0x17C]; s32 *f17C; } Tab;
extern Ctx *D_00167F38;
extern Tab D_001B7258;
extern void func_01EC9CB0(u32);

s32 func_01ECA098(void) {
    s32 i;
    for (i = 0; i < D_00167F38->f100; i++) {
        if (D_001B7258.f17C[i] == 0) {
        } else {
            func_01EC9CB0(i);
        }
    }
    return 0;
}
