/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 w[6]; } Ring;
typedef struct { char _p0[0x10]; void *f10; char _p14[0x18]; Ring q; char _p44[0]; } Ent;
typedef struct { char _p0[0x10C]; u32 f10C; } Ctx;
typedef struct { char _p0[0x130]; Ent *f130; } Tab;
extern Ctx *D_00167F38;
extern Tab D_001B7258;
extern void func_01EA06A8(void **);
extern void func_01EA6D00(Ring *);
s32 func_01ECCA90(void) {
    u32 i;
    if (D_001B7258.f130 == 0) {
        return 0;
    }
    for (i = 0; i < D_00167F38->f10C; i++) {
        if (D_001B7258.f130[i].f10 != 0) {
            func_01EA06A8(&D_001B7258.f130[i].f10);
        }
        if (&D_001B7258.f130[i].q != 0) {
            func_01EA6D00(&D_001B7258.f130[i].q);
        }
    }
    return 0;
}
