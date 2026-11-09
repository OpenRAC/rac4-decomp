#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

typedef struct Type2 {
    void (*fn)(s32);
    s32 pad[4];
} Type2;

extern void func_00497628(s32 *current, s32 count, void (*predicate)(void));
extern s32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_0049C290(s32 param, s32 count);
extern void func_0049C400(s32 slot, s32 offset, s32 param_a, s32 param_b, s32 mode);
extern void func_0049D170(s32 param_a, s32 param_b, s32 source);
extern void func_0049D280(s32 player, s32 count);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004B8928(void);
extern void func_004B89E0(void);
extern void func_004B8C50(void);
extern void func_004B8908(void);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern s32 func_00506120(u32 id, u32 value);

extern Type2 D_003D9380[];
extern u8 D_001CDAA0[];
extern s32 D_00221790;
extern Type1 D_0030A160[];

void func_004B7E78(void) {
    s32 player;
    Type1 *e;
    s32 v;

    player = func_00505B20();
    e = &D_0030A160[player];
    func_004B8C50();
    e->f8 = func_00499CA0(D_001CDAA0, -1);
    func_005054F8(func_004A1A60(&D_00221790, 1), 1);
    func_00506120(func_004A1A60(&D_00221790, 1), e->f8);
    e->fC = func_00499CA0(D_001CDAA0 + 0x18, -1);
    func_005054F8(func_004A1A60(&D_00221790, 2), 1);
    func_00506120(func_004A1A60(&D_00221790, 2), e->fC);
    e->f0 = 1;
    e->f4 = 0;
    do {
        func_004B8928();
        D_003D9380[e->f4].fn(0);
        e->f4++;
    } while (e->f4 < 6);
    func_00497628(&e->f4, 6, func_004B8908);
    func_0049D170(player, 0, func_004A1A60(&D_00221790, 0x10));
    func_0049D280(player, 1);
    v = D_00221790;
    func_0049C400(player, 0, v, func_004A1A60(&D_00221790, 0x10), 0);
    func_0049C290(player, 1);
    func_004B89E0();
}
