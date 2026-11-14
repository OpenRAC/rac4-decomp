#include "common.h"

extern void func_L00_0066CCE8(void *, s32);

typedef struct Type1 {
    char _p0[0x34];
    u16 f34;
    char _p36[0x98 - 0x36];
    s32 f98;
    char _p9C[0xAC - 0x9C];
    struct Type2 *fAC;
} Type1;

typedef struct Type2 {
    char _p0[0x18];
    Type1 *f18;
    Type1 *f1C;
} Type2;

// Set flags 0x41 and clear 0x1000 at +0x34, zero +0x98 of the moby and its two linked mobys, then update each.
void func_L41_00446208(Type1 *arg0) {
    Type2 *p = arg0->fAC;

    if (p->f18 != 0) {
        p->f18->f34 |= 0x41;
        p->f18->f34 &= 0xEFFF;
        p->f18->f98 = 0;
        func_L00_0066CCE8(p->f18, 1);
    }
    if (p->f1C != 0) {
        p->f1C->f34 |= 0x41;
        p->f1C->f34 &= 0xEFFF;
        p->f1C->f98 = 0;
        func_L00_0066CCE8(p->f1C, 1);
    }
    arg0->f34 |= 0x41;
    arg0->f34 &= 0xEFFF;
    arg0->f98 = 0;
    func_L00_0066CCE8(arg0, 1);
}
