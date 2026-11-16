/* Not matching yet: BYTES 22/116 (tools/try_func.py func_L01_004BC7A0 --diff) (tools/try_func.py func_L01_004BC7A0 --diff). Not part of the build. */
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

extern u8 *D_222D14;

s32 D_222E20 = 0;

void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

int func_L01_004BC7A0(Obj *o) {
    Child *c;
    s32 off;
    if (o->f20 != 0) {
        return 0;
    }
    c = o->fAC;
    c->f40 = o->fF0;
    off = (c->f8 << 8) + (s32)D_222D14;
    *(s128 *)((u8 *)off + 0xF0) = o->fF0;
    D_222E20 = 0;
    o->f30 = 0xFF;
    o->f74 |= 2;
    func_L01_00591BD8((u8 *)o, 1, 0);
    return 1;
}
