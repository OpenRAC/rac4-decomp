#include "common.h"

typedef struct Q { char _p0[0x34]; char *f34; char _p38[0x8]; f32 f40; char _p44[0xC]; s32 f50; s32 f54; s32 f58; f32 f5C; } Q;
void func_004A0F98(Q *, s32, f32 *, f32 *);

void func_004A15D0(Q *p) {
    f32 a[2];
    s32 i = 0;
    p->f40 = 0;
    if (p->f50 != 0) {
        a[1] = p->f40;
        for (; i < p->f50; i++) {
            func_004A0F98(p, i, &a[0], &a[1]);
            *(f32 *)(p->f34 + i * 0x18 + 0x10) = -(p->f40 + a[1] * 0.5f);
            p->f40 = p->f40 + a[1];
        }
    }
    p->f58 |= 2;
}
