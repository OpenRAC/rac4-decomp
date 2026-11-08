#include "common.h"

typedef struct {
    u8 pad[0x10];
    u32 flags;
} Obj_461220;
extern Obj_461220 *func_00476F70(s32);
extern s32 D_00242458[];

/* PAL: from rac3-decomp's func_L01_00337EF8 */
s32 func_L01_00461220(void) {
    Obj_461220 *p = func_00476F70(D_00242458[0]);
    if (p != 0 && (p->flags & 2)) return 1;
    return 0;
}
