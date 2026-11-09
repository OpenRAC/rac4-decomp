#include "common.h"

typedef struct Obj {
    u8 pad0[0xAC];
    s32 fAC;
} Obj;

typedef struct Type1 {
    u8 pad0[0x84];
    s16 f84;
    u8 pad86[0x1F0 - 0x86];
    Obj *f1F0[1];
} Type1;

extern Type1 D_00237000;

extern void func_0046BDD0(Obj *arg0);

void func_004F3538(void) {
    s32 i;
    Obj *o;

    for (i = 0; i < D_00237000.f84; i++) {
        o = D_00237000.f1F0[i];
        if (o != 0) {
            o->fAC = 0;
            func_0046BDD0(o);
            D_00237000.f1F0[i] = 0;
        }
    }
}
