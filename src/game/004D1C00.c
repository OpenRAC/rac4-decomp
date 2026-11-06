#include "common.h"

typedef struct Type3 {
    char _p0[0x8];
    s32 f8;
    s32 fC;
} Type3;

typedef struct Type2 {
    char _p0[0x8];
    Type3 *f8;
    char _pC[0xC];
} Type2;

typedef struct Type1 {
    char _p0[0x34];
    Type2 *f34;
    char _p38[0x1C];
    s32 f54;
} Type1;

typedef struct Type4 {
    char _p0[0x8];
    s32 f8;
    char _pC[0x4];
    s32 f10;
    char _p14[0xDC];
    Type1 fF0;
    char _p148[0x14];
} Type4;

typedef struct Type5 {
    s32 f0;
    s32 f4;
} Type5;

extern s32 func_0045E038(s32);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_00499CE0(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(u32, const char *);
extern s32 func_00505B20(void);
extern s32 func_00506120(u32 id, u32 value);

extern Type5 D_001CDED8[];
extern s32 D_002219C0;
extern Type4 D_0031B050[];

static inline Type2 *func_004D1C00_get(Type1 *s)
{
    if (s->f54 < 0) {
        return 0;
    }
    return &s->f34[s->f54];
}

void func_004D1C00(void)
{
    Type4 *e = &D_0031B050[func_00505B20()];
    Type3 *t = func_004D1C00_get(&e->fF0)->f8;
    s32 id = func_004A1A60(&D_002219C0, 0x10);
    Type5 *d;

    func_00505238(id, (const char *)func_0045E038(t->f8));
    d = &D_001CDED8[t->fC];
    if (e->f10 != 0) {
        func_00499CE0(e->f10);
        e->f10 = 0;
    }
    e->f10 = func_00499CA0(d, -1);
    func_00506120(func_004A1A60(&D_002219C0, 0xB), e->f10);
    e->f8 &= ~2;
}
