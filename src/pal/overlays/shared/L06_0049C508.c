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

extern s32 D_0021E714;
extern s32 D_0021E718;
extern void func_0046C6B0(u8 *);
extern void func_00474368(u8 *, s32, s32);
extern s32 func_00453D50(s16 *);
extern s32 func_L06_0049C768(void);
extern u8 *func_00511CC0(s32);
extern s32 func_0047C378(u128, s32);
extern s32 func_0046BE78(u8 **, u8 *, s32);
extern void func_00520F80(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);

// State machine of a moby: state 1 waits for the countdown at vars+0xA; state 2 tests which of the two
// entries of func_00511CC0 is inside area vars+0, and moves on to state 3 when exactly one is;
// state 3 calls func_00520F80 from one to the other and goes back to state 1.
void func_L06_0049C508(u8 *moby) {
    Vars *v;
    s32 mask;
    s32 i;
    u8 *p;
    u8 *out;

    if (D_0021E714 != 0 || D_0021E718 != 1) {
        func_0046C6B0(moby);
        return;
    }
    v = *(Vars **)(moby + 0xAC);
    if (moby[0x20] == 0) {
        if (v->area0 == -1) {
            func_0046C6B0(moby);
            return;
        }
        v->busy = 0;
        v->timer = 0;
        func_00474368(moby, 2, -1);
    }
    switch (moby[0x20]) {
    case 1:
        if (func_00453D50(&v->timer)) {
            func_00474368(moby, 2, -1);
        }
        break;
    case 2:
        if (func_L06_0049C768() != 0) {
            break;
        }
        mask = 0;
        for (i = 0; i < 2; i++) {
            if (func_0047C378(*(u128 *)(func_00511CC0(i) + 0xA0), v->area0)) {
                mask |= 1 << i;
            }
        }
        if (mask == 0 || mask == 3) {
            break;
        }
        i = mask & 1;
        mask = 1;
        p = func_00511CC0(i);
        v->from = p;
        if (v->area1 != -1 && func_0047C378(*(u128 *)(p + 0xA0), v->area1)) {
            break;
        }
        v->to = func_00511CC0(mask - i);
        func_00474368(moby, 3, -1);
        break;
    case 3:
        if (func_L06_0049C768() != 0 ||
            (v->area1 != -1 && func_0047C378(*(u128 *)(v->from + 0xA0), v->area1))) {
            func_00474368(moby, 2, -1);
            break;
        }
        v->busy = 1;
        if (func_0046BE78(&out, v->to, 0)) {
            func_00520F80(v->from, out, out + 0x10, -1, 1, 1, 0, 1);
            v->timer = (s32)((f32)v->secs * 50.0f);
            func_00474368(moby, 1, -1);
        }
        v->busy = 0;
        break;
    }
}
