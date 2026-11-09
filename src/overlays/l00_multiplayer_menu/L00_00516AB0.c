/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Obj Obj;
typedef struct ObjVt {
    s32 pad0;
    s32 pad4;
    s32 (*fn)(Obj *, s32, s32);
} ObjVt;
struct Obj {
    ObjVt *vt;
    s64 (*cb)();
    s32 pad8;
    s32 unkC;
    s32 pad10;
    s32 unk14;
    s32 pad18[5];
    s32 unk2C;
    s32 pad30[2];
    s64 unk38;
};

void func_L00_004F84C8(s32, s32, s32, s32, s32);
s64 func_L00_00516C48(Obj *, s32, s32, s32);

s32 func_L00_00516AB0(Obj *o, s32 a1, s32 a2) {
    s64 (*cb)();
    s32 ret;

    if (o == NULL) {
        return 0;
    }
    cb = o->cb;
    if (o->vt == NULL || o->vt->fn == NULL) {
        func_L00_004F84C8(0x20, 0x6A, 0x6F, 0, 0);
        return -2;
    }
    if (cb != NULL) {
        ret = cb(o, 3, a1, a2, 0, 1);
        if (ret <= 0) {
            return ret;
        }
    }
    if (o->unkC == 0) {
        func_L00_004F84C8(0x20, 0x6A, 0x6E, 0, 0);
        return -2;
    }
    ret = o->vt->fn(o, a1, a2);
    if (ret > 0) {
        o->unk38 += ret;
    }
    if (o->unk14 & 0x10) {
        ret = func_L00_00516C48(o, 0xB, 0, 0);
        if (ret <= 0) {
            return ret;
        }
    }
    if (o->unk2C <= 0) {
        func_L00_004F84C8(0x20, 0x6A, 0x2A, 0, 0);
        return 0;
    }
    if (cb != NULL) {
        ret = cb(o, 0x83, a1, a2, 0, ret);
    }
    return ret;
}
