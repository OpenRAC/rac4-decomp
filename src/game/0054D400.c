#include "common.h"

typedef struct {
    u8 pad0[0x720];
    char a[7][0x20];
    char b[7][0x20];
    s32 n1;
    char c[6][0x20];
    char d[6][0x20];
    s32 n2;
} Type0;

extern Type0 D_00355320;
f32 D_00221060 = 100.0f, D_00221064 = 410.0f, D_00221068 = 75.0f, D_0022106C = 18.0f;
extern void func_004574D8(s32 x, s32 y, u64 a, void *b, s32 c);
extern void func_00457648(u64 color, const char *first, s32 second, f32 x, f32 y, f32 depth);

void func_0054D400(void)
{
    s32 i;
    s32 n;

    for (i = 0; i < D_00355320.n1; i++) {
        func_00457648((s32)0x80808080, D_00355320.a[i], -1, D_00221060, D_00221068 + (f32)i * D_0022106C, 1.0f);
        func_004574D8((s32)D_00221064, (s32)(D_00221068 + (f32)i * D_0022106C), (s32)0x80808080, D_00355320.b[i], -1);
    }
    n = D_00355320.n1;
    for (i = 0; i < D_00355320.n2; i++) {
        f32 y = D_00221068 + (f32)(i + n) * D_0022106C;
        func_00457648((s32)0x80808080, D_00355320.c[i], -1, D_00221060, y, 1.0f);
        func_004574D8((s32)D_00221064, (s32)y, (s32)0x80808080, D_00355320.d[i], -1);
    }
}
