#include "common.h"

typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x8];
    s32 f8;
    u8 pad1[0x40 - 0xC];
    s128 f40;
} Child;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x30 - 0x21];
    u8 f30;
    u8 pad2[0x74 - 0x31];
    u16 f74;
    u8 pad3[0xAC - 0x76];
    Child *fAC;
    u8 pad4[0xF0 - 0xB0];
    s128 fF0;
} Obj;

extern Obj *D_00222D14;

s32 D_00221F18 = 0;

void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

int func_L01_004BC7A0(Obj *o) {
    Child *c;
    if (o->f20 != 0) {
        return 0;
    }
    c = o->fAC;
    *(s128 *)((u8 *)c + 0x40) = o->fF0;
    D_00222D14[c->f8].fF0 = o->fF0;
    D_00221F18 = 0;
    *(u8 *)((u8 *)o + 0x30) = 0xFF;
    *(u16 *)((u8 *)o + 0x74) |= 2;
    func_L01_00591BD8((u8 *)o, 1, 0);
    return 1;
}
