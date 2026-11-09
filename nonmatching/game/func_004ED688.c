/* Not matching yet: BYTES 7/288 (tools/try_func.py func_004ED688 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    u16 h[0x1C];
} Type1;

typedef struct {
    f32 v[8];
    Type1 b;
} Type2;

typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Type3;

extern Type3 D_00327A60;
extern s32 D_00221270[];

extern void func_0044B250(float *a, float b, float c, float d, float e);
extern void func_0044B680(const f32 *vertices, u32 color, u64 texture);
extern void func_0044D2B8(void *a, s32 b, s32 c, s32 d);
extern s32 func_0045EB60(s32, s32);
extern s64 func_0045EC28(s32);
extern void *func_00549AE8(s32 arg0);
extern s32 func_0054A268(s32 arg0, s32 arg1);

void func_004ED688(void) {
    Type2 q;
    s64 tex;

    q.b = *(Type1 *)func_00549AE8(func_0054A268(D_00327A60.unk8, D_00327A60.unkA + 1));
    func_0044B250(q.v, 390.0f, 345.0f, 430.0f, 385.0f);
    tex = func_0045EC28(func_0045EB60(q.b.h[0xE], 0));
    func_0044D2B8(D_00221270, 2, 1, 1);
    func_0044B680(q.v, 0xAAAAAAAA, tex);
}
