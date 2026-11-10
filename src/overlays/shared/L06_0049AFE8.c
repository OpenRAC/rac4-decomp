#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct {
    s32 area0;
    s32 area1;
    s16 secs;
    s16 timer;
    u8 *from;
    u8 *to;
    u8 busy;
} Vars;

extern s32 D_0021E694;
extern s32 D_0021E698;
extern void func_0046BDD0(u8 *);
extern void func_00473A88(u8 *, s32, s32);
extern s32 func_00453538(s16 *);
extern s32 func_L06_0049B248(void);
extern u8 *func_00510BE8(s32);
extern s32 func_0047BA40(u128, s32);
extern s32 func_0046B5B8(u8 **, u8 *, s32);
extern void func_0051FDC0(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);

void func_L06_0049AFE8(u8 *moby) {
    Vars *v;
    s32 mask;
    s32 i;
    u8 *p;
    u8 *out;

    if (D_0021E694 != 0 || D_0021E698 != 1) {
        func_0046BDD0(moby);
        return;
    }
    v = *(Vars **)(moby + 0xAC);
    if (moby[0x20] == 0) {
        if (v->area0 == -1) {
            func_0046BDD0(moby);
            return;
        }
        v->busy = 0;
        v->timer = 0;
        func_00473A88(moby, 2, -1);
    }
    switch (moby[0x20]) {
    case 1:
        if (func_00453538(&v->timer)) {
            func_00473A88(moby, 2, -1);
        }
        break;
    case 2:
        if (func_L06_0049B248() != 0) {
            break;
        }
        mask = 0;
        for (i = 0; i < 2; i++) {
            if (func_0047BA40(*(u128 *)(func_00510BE8(i) + 0xA0), v->area0)) {
                mask |= 1 << i;
            }
        }
        if (mask == 0 || mask == 3) {
            break;
        }
        i = mask & 1;
        mask = 1;
        p = func_00510BE8(i);
        v->from = p;
        if (v->area1 != -1 && func_0047BA40(*(u128 *)(p + 0xA0), v->area1)) {
            break;
        }
        v->to = func_00510BE8(mask - i);
        func_00473A88(moby, 3, -1);
        break;
    case 3:
        if (func_L06_0049B248() != 0 ||
            (v->area1 != -1 && func_0047BA40(*(u128 *)(v->from + 0xA0), v->area1))) {
            func_00473A88(moby, 2, -1);
            break;
        }
        v->busy = 1;
        if (func_0046B5B8(&out, v->to, 0)) {
            func_0051FDC0(v->from, out, out + 0x10, -1, 1, 1, 0, 1);
            v->timer = (s32)((f32)v->secs * 60.0f);
            func_00473A88(moby, 1, -1);
        }
        v->busy = 0;
        break;
    }
}
