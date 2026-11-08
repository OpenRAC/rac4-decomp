#include "common.h"

typedef struct {
    u8 pad[0x10];
    s32 flags;
} Obj_0045FF38;
extern Obj_0045FF38 *func_00476690(void *);
extern void *D_00242358[];

/* from rac3-decomp's func_L01_00337EF8 */
s32 func_L01_0045FF38(void) {
    Obj_0045FF38 *p = func_00476690(D_00242358[0]);
    if (p != 0 && (p->flags & 2)) return 1;
    return 0;
}
