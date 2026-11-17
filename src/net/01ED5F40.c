/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0, f4, f8; } Obj;
extern void *func_0011A518(void *, s32, u32);
extern s32 D_00169CD4;
s32 func_01ED5F40(Obj *o) {
    if (o == 0) {
        return -0x15;
    }
    func_0011A518(o, 0, 0xC);
    o->f0 = D_00169CD4;
    o->f4 = 1;
    return 0;
}
