#include "common.h"

typedef struct {
    char pad0[0x8];
    char head[0x19 - 0x8];
    char bits[0x1DC - 0x19];
    s32 count;
} Obj;
extern void func_005BCBF0(char *, char *, s32);
extern f32 func_00135770(f32);

/* from rac3-decomp's func_L39_0066EE90 */
s32 func_L00_006F7218(Obj *o, char *dst) {
    s32 ret;
    if (o->count == -1) {
        ret = 0;
    } else {
        func_005BCBF0(dst, o->head, 8);
        dst += 8;
        func_005BCBF0(dst, o->bits, (s32)func_00135770(o->count * 0.125f));
        ret = (s32)func_00135770(o->count * 0.125f) + 8;
    }
    return ret;
}
