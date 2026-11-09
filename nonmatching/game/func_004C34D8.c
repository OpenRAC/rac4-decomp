/* Not matching yet: BYTES 77/712 (tools/try_func.py func_004C34D8 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    char pad[0x18];
    s32 sel;
    char pad1C[0x3C];
    s8 slots[10];
    char rest[0x12];
} State;

typedef struct {
    s32 a;
    s32 b;
} Pair;

extern State D_0030B7F8[];
extern s32 D_00221888;
extern Pair D_003D2248[];
extern Pair D_003D22E0[];
extern s32 D_003D2320[];

extern s32 func_00505B20(void);
extern s32 func_004A1A60(s32 *, s32);
extern void func_00505328(s32, u32);
extern void func_0049C158(s32, s32, s32, s32);
extern void func_0049C200(s32, s32);
extern void func_0049C248(s32, s32);
extern void func_00504550(s32, f32 *, f32 *);
extern void func_00504648(s32, f32 *, f32 *);
extern void func_0049BFC0(s32, s32, s32, f32, f32, f32, f32);
extern void *func_00549AE8(s32);
extern s32 func_0045E038(s32);
extern void func_00505238(s32, s32);

void func_004C34D8(void)
{
    f32 v[5];
    f32 x, w, h;
    s32 i = 0;
    s32 lo = 10;
    s32 hi = -1;
    s32 index = func_00505B20();
    State *p = &D_0030B7F8[index];
    s8 *slot = p->slots;
    s32 text;

    func_00505328(func_004A1A60(&D_00221888, D_003D22E0[p->sel].a), 0x80D0D0D0);
    func_00505328(func_004A1A60(&D_00221888, D_003D2320[p->sel]), 0x80D0D0D0);
    func_0049C158(index, 3, func_004A1A60(&D_00221888, D_003D22E0[p->sel].b), 0);
    func_0049C200(index, 3);
    do {
        if (*slot == p->sel + 1) {
            func_00505328(func_004A1A60(&D_00221888, D_003D2248[i].a), 0x80D0D0D0);
            if (i < lo) lo = i;
            if (hi < i) hi = i;
        }
        i++;
        slot++;
    } while (i < 10);
    if (lo <= hi) {
        func_00504550(func_004A1A60(&D_00221888, D_003D2248[lo].a), &v[0], &v[1]);
        func_00504550(func_004A1A60(&D_00221888, D_003D2248[hi].a), &v[2], &v[1]);
        func_00504648(func_004A1A60(&D_00221888, D_003D2248[lo].a), &v[3], &v[4]);
        x = (v[2] + v[0]) * 0.5f;
        w = v[3] + (v[2] - v[0]) + 0.01171875f;
        h = v[4] + 0.014423077f;
        v[0] = x;
        v[4] = h;
        v[3] = w;
        func_0049BFC0(index, 2, 0, x, v[1], w, h);
        func_0049C200(index, 2);
    } else {
        func_0049C248(index, 2);
    }
    text = func_004A1A60(&D_00221888, 0x50);
    func_00505238(text, func_0045E038(*(s16 *)((u8 *)func_00549AE8(p->sel + 1) + 0x2A)));
}
