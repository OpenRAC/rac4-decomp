/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x10]; s32 f10; char _p14[4]; s32 f18; } Type1;
extern Type1 D_001BD290;
extern s16 D_00169CD8;
extern void (*D_001BCB40)(void *, s32);
extern s32 D_001BC948;
s32 func_01EDDD30(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    if (*(s32 *)(arg3 + 0x18) == 0 && D_001BD290.f10 != 0) {
        D_00169CD8 = 1;
    }
    if (D_001BD290.f18 == 1) {
        D_001BD290.f18 = 0;
    } else if (D_001BCB40 != NULL) {
        D_001BCB40(arg3, D_001BC948);
    }
    return 0x34;
}
