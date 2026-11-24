#include "common.h"

typedef struct Game {
    u8 pad0[0x40];
    s32 mode;
    u8 pad44[0x10];
    s32 x54;
    s32 x58;
    s32 x5C[4];
    s32 x6C[4];
    s16 x7C;
    s16 x7E;
    s32 x80;
    u8 pad84[0x4];
    s32 x88;
    u8 pad8C[0xC];
    s32 x98;
    s32 x9C;
    s32 xA0;
} Game;

typedef void (*Callback)(void);

extern Game D_00239760;
extern s32 D_0021EDA0;
extern s32 D_00171BAC[];
extern s32 D_0021DE3C;
extern u8 D_00171E75[];
extern f32 D_003D0738[];
extern s32 func_004801B8(void);
extern void func_00158878(s32);
extern void func_00489F10(s32);
extern Callback *func_0046DD08(s32, s32, s32);
extern void func_004E3138(s32, s32, s32);
extern char *func_0045E850(s32);
extern void func_0049F4C8(s32, char *, s32, s32, s32, s32, s32, f32);

// Starts game mode mode (0 keeps the current one): stores it with arg, resets
// the mode state, runs the registered start callback and, for modes 9, 0x10
// and 2, passes the matching text to func_004E3138 or func_0049F4C8.
void func_0045A210(s32 mode, s32 arg)
{
    Callback *cb;
    s32 i;
    Game *g;
    s32 flag;
    f32 f;

    if (mode == 0) {
        mode = D_00239760.mode;
    }
    D_0021EDA0 = mode;
    if (mode == 5) {
        D_00239760.x80 = D_00171BAC[0];
    } else {
        D_00239760.x80 = 0;
    }
    g = &D_00239760;
    g->x54 = arg;
    g->x7E = mode == 11;
    g->mode = mode;
    g->x7C = 0;
    g->x58 = 0;
    if (func_004801B8() == 3 || func_004801B8() == 0x10) {
        flag = 0;
    } else {
        flag = 1;
    }
    g->x88 = flag;
    if (D_0021DE3C != 3) {
        func_00158878(1);
        if (mode != 11) {
            func_00489F10(0);
        }
    }
    for (i = 0; i < 4; i++) {
        D_00239760.x5C[i] = 0;
        D_00239760.x6C[i] = 0;
    }
    cb = func_0046DD08(0x2120, 0, 12);
    if (cb != 0 && *cb != 0) {
        (*cb)();
    }
    if (mode == 9) {
        func_004E3138(0x12, 0, 0);
    } else if (mode == 0x10) {
        func_0049F4C8(4, func_0045E850(D_00239760.x98), D_00239760.xA0, D_00239760.x9C, 0, 0, 0, -1.0f);
    } else if (mode == 2) {
        f = D_003D0738[D_00171E75[0]];
        func_0049F4C8(4, func_0045E850(0x3464), 0, 1, 0, 0, 0, f);
    }
}
