/* Not matching yet: SIZE ours 192 / retail 188 (the FP-compare nop; unreachable with every shipped cc1) (tools/try_func.py func_01EFC598 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

char *func_0011AFC8(char *, char *, s32);
void func_01EFBFB4(u8 *p);

typedef struct Obj Obj;

typedef struct {
    u8 pad[0x7C];
    f32 (*fn)(Obj *, s32, s32);
} Vt;

struct Obj {
    u8 pad000[0xB0];
    Vt *f0B0;
    u8 pad0B4[0x2C0 - 0xB4];
    s32 f2C0;
    u8 pad2C4[0x2DC - 0x2C4];
    s32 f2DC;
    s32 f2E0;
    u8 pad2E4[0x4E4 - 0x2E4];
    f32 f4E4;
};

void func_01EFC598(Obj *obj, char *arg1, s32 arg2) {
    f32 f;

    func_01EFBFB4((u8 *)obj);
    func_0011AFC8((char *)obj + 0xB8, arg1, 0x200);
    obj->f2C0 = arg2;
    obj->f2E0 = arg2;
    f = obj->f0B0->fn(obj, 0, arg2);
    if (obj->f2C0 > 0 && obj->f4E4 < f) {
        obj->f2DC = obj->f2C0;
        do {
            obj->f2DC = obj->f2DC - 1;
        } while (obj->f0B0->fn(obj, obj->f2DC, obj->f2C0) < obj->f4E4);
    }
}
