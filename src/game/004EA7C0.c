#include "common.h"

typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct Rec20 {
    u128 v0;
    f32 f10;
    f32 f14;
    f32 f18;
    void *f1C;
} Rec20;

extern u128 func_0047ACC0(u128, s32, void *);
extern void *func_00510BE8(s32);
extern s32 D_0021EDD4;
extern Rec20 D_00326A60[];

s32 func_004EA7C0(void *arg0, u128 *arg1, void *arg2, f32 x, f32 y, f32 z) {
    Rec20 *r;
    s32 i;
    u128 v;

    if (arg2 == NULL) {
        arg2 = func_00510BE8(0);
    }
    for (i = 0; i < 0x80; i++) {
        if (D_00326A60[i].f1C == NULL) {
            if (arg1 != NULL) {
                v = *arg1;
            } else {
                v = *(u128 *)((u8 *)arg0 + 0x10);
            }
            r = &D_00326A60[i];
            r->f1C = arg0;
            r->f10 = x;
            r->f14 = y;
            r->f18 = z;
            if (D_0021EDD4 == 0 && *(s16 *)((u8 *)arg2 + 0x2F8) != 0) {
                r->v0 = *(u128 *)(*(u8 **)((u8 *)arg2 + 0x2EF0) + 0xE0);
            } else {
                r->v0 = func_0047ACC0(v, 1, arg2);
            }
            return i;
        }
    }
    return -1;
}
