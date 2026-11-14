/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { char a[0x101]; char b[0x101]; char _p202[2]; s32 f204; } Obj;
extern void *func_0011A518(void *, s32, u32);
void func_01EEF7A0(Obj *o) {
    o->f204 = -1;
    func_0011A518(o->a, 0, 0x101);
    func_0011A518(o->b, 0, 0x101);
}
