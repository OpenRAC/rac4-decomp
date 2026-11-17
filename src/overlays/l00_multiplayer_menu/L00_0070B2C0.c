#include "common.h"

typedef struct { char c[8]; } B8;
extern s32 D_003F3D70[];
extern B8 D_00220A88[];
extern void func_L00_00709AC8();
/* Build a request on the stack and pass it on. */
void func_L00_0070B2C0(s32 arg0) {
    struct { s32 f0; s32 f4; s32 f8; char pad[0xF]; B8 s; char rest[0x1A0 - 0x2B]; } b;
    b.f0 = D_003F3D70[0];
    b.f4 = 1;
    b.f8 = arg0;
    b.s = D_00220A88[0];
    func_L00_00709AC8(&b);
}
