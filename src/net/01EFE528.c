/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u8 D_0019D990[];

typedef struct {
    u8 pad0[0xC];
    void (*fC)(void *, s32, void *);
} Vtbl;

typedef struct {
    Vtbl *vt;
} Obj;

extern Obj *func_01EEE39C(void);

void func_01EFE528(s32 *arg0) {
    Obj *obj;

    if (arg0[4] != 0) {
        if (arg0[0x2E] == 0) {
            obj = func_01EEE39C();
            obj->vt->fC(obj, 2, D_0019D990);
        } else {
            obj = func_01EEE39C();
            obj->vt->fC(obj, 3, D_0019D990);
        }
        arg0[0x2E] = (arg0[0x2E] == 0);
    }
}
