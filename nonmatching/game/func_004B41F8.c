/* Not matching yet: BYTES 6/332 (tools/try_func.py func_004B41F8 --diff). Not part of the build. */
#include "common.h"

typedef struct Entry24 {
    s32 f0;
    s32 f4;
    char f8[20];
    void (*f1C)(struct Entry24 *);
    s32 f20;
} Entry24;

typedef struct {
    u8 pad0[0x84];
    s32 count;
    Entry24 entries[1];
} Type3096A8;

typedef struct {
    s32 a;
    s32 b;
} Pair;

extern s32 func_0045E038(s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00504F68(s32, s32);
extern void func_00505238(s32, s32);
extern void func_00505328(s32, u32);

extern Pair D_003D1C48[];
extern s32 D_00221748;
extern Type3096A8 D_003096A8;

void func_004B41F8(s32 arg0, void (*arg1)(Entry24 *), s32 arg2, s32 arg3)
{
    s32 n = D_003096A8.count;
    Entry24 *e;
    s32 *pb;
    s32 *pa;
    s32 t;

    D_003096A8.count = n + 1;
    pa = &D_003D1C48[n].a;
    pb = &D_003D1C48[n].b;
    e = &D_003096A8.entries[n];
    e->f4 = arg0;
    e->f1C = arg1;
    e->f20 = arg2;
    e->f0 = 0;
    e->f8[0] = 0;
    func_00504F68(func_004A1A60(&D_00221748, *pb), 1);
    func_00504F68(func_004A1A60(&D_00221748, *pa), 1);
    t = func_004A1A60(&D_00221748, *pa);
    func_00505238(t, func_0045E038(arg3));
    func_00505238(func_004A1A60(&D_00221748, *pb), (s32)D_003096A8.entries[n].f8);
    func_00505328(func_004A1A60(&D_00221748, *pb), 0x80404040);
    if (e->f1C != 0) {
        e->f1C(e);
    }
}
