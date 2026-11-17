/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 a, b; } P8;
typedef struct Obj Obj;
struct Obj { char _p0[0x44]; void (*f44)(Obj *, s32, s32, P8, s32, s32); s32 f48; };
void func_01EC2928(Obj *o, s32 a1, P8 p, s32 a3) {
    o->f44(o, a1, 0, p, a3, o->f48);
}
