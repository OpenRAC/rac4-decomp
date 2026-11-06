#include "common.h"

typedef struct { u8 pad[0x8C]; s16 type; } Obj;
typedef struct { u8 pad[0x10]; void (*fn)(Obj *); } TypeInfo;
extern TypeInfo D_003F0F00[];

/* Calls the handler at +0x10 of the 0x14-byte type record D_003F0F00[o->type] with o, when there is one. */
void func_0043AEF8(Obj *o) {
    void (*fn)(Obj *) = D_003F0F00[o->type].fn;
    if (fn != 0) {
        fn(o);
    }
}
