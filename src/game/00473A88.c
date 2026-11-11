#include "common.h"

typedef struct Obj {
    char pad0[0x20];
    u8 f20;
    char pad21[0x47];
    u8 f68;
    u8 f69;
    u16 f6A;
    char pad6C[0x52];
    u8 fBE;
} Obj;

void func_00473A88(Obj *o, u8 state, s32 type) {
    u8 flags = o->fBE & 0xFE;
    u8 prev = o->f20;
    o->f20 = state;
    o->f68 = prev;
    o->f6A = 0;
    o->fBE = flags;
    if (type != -1) {
        o->f69 = type;
        o->fBE = flags & 0xFD;
    }
}
