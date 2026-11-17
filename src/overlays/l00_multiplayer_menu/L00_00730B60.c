#include "common.h"

extern s32 func_00765A40(s32);
extern s32 func_L00_005C9F50(s32);
extern s32 func_L00_0077C668(s32);
extern u8 *D_002233A4;

typedef struct S2 { u8 pad[0xE8]; void (*fE8)(void *, s32); } S2;
typedef struct S1 { u8 pad[0x58]; S2 *f58; } S1;
typedef struct S0 { u8 pad[0x100]; S1 *f100; } S0;

// Show menu text 0xF79, then 0xF7A or 0xF7B depending on func_00765A40's result.
s32 func_L00_00730B60(S0 *arg0) {
    S2 *t;
    s32 r;
    func_L00_0077C668(*(s32 *)(D_002233A4 + 0x68));
    t = arg0->f100->f58;
    t->fE8(arg0->f100, func_L00_005C9F50(0xF79));
    r = func_00765A40(*(s32 *)(D_002233A4 + 0x34));
    if (r != 0) {
        t = arg0->f100->f58;
        t->fE8(arg0->f100, func_L00_005C9F50(0xF7A));
    } else {
        t = arg0->f100->f58;
        t->fE8(arg0->f100, func_L00_005C9F50(0xF7B));
    }
    return r;
}
