/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char f4[0x18]; s32 f1C; } Obj;
extern void *func_00403308(void *, s32, u32);
s32 func_00413758(Obj *);
void func_0040DE18(Obj *o, s32 a1) {
    func_00403308(o->f4, 0, 0x18);
    if (func_00413758(o) == 0) {
        o->f1C = a1;
    }
}
