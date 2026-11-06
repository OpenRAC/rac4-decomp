/* cflags:  */
#include "common.h"

typedef struct {
    u32 f0;
    u32 f4;
    u16 f8;
    u16 fA;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2C;
} L01_00573560_Entry;

typedef struct {
    u32 f0;
    u32 f4;
    f32 f8;
    u32 fC;
    u32 f10;
    u16 f14;
    u16 f16;
    u32 f18;
    u32 f1C;
} L01_00573560_Obj1;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    f32 f18;
} L01_00573560_Obj0;

extern L01_00573560_Entry D_0024F220[];

/* Adds a scaled float amount to a table entry's u16 counter, clamped to 0x400 */
f32 func_L01_00576370(L01_00573560_Obj0 *arg0, L01_00573560_Obj1 *arg1) {
    L01_00573560_Entry *e;
    f32 d;
    s32 v;

    d = arg0->f18 * arg1->f8;
    e = &D_0024F220[arg1->f14];
    v = e->fA + (s32)d;
    if (v >= 0x401) {
        v = 0x400;
    }
    e->fA = v;
    return d;
}
