#include "common.h"

// D_0021F840 and D_0021F870 must be defined in this translation unit (retail reaches them through
// $gp outside a delay slot); D_0021F840 is also defined in src/game/004B85D8.c, so landing this
// means putting both functions in one file.

typedef struct {
    u8 prefix[0x2F10];
    s32 slot;
} Player;
extern s32 func_00505B20(void);
extern Player *func_00510BE8(s32 arg0);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_0045E038(s32);
extern s32 func_00505238(s32, s32);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F840 = 0;
s32 D_0021F870[2] = { 0x192, 0x193 };
extern s32 D_001711D0[];
extern s32 D_00171D80[][4];
extern s32 D_00171E78[][10];
extern s32 D_00221790;
extern s32 D_003D93A4[];

void func_004B84D0(s32 arg0) {
    s32 slot;
    s32 n;
    s32 v;
    s32 t;
    s32 *on;
    s32 *shown;

    n = func_00505B20();
    slot = func_00510BE8((D_0021EDD4 == 0 && D_0021EDD8 == 1) ? (D_0021F840 != 1) : n)->slot;
    on = &D_00171E78[D_001711D0[slot]][slot];
    shown = &D_00171D80[D_001711D0[slot]][slot];
    if (arg0) {
        v = (*on & 1) ^ 1;
        *shown = v;
        *on = v;
        func_00497980(0x10);
    }
    t = func_004A1A60(&D_00221790, D_003D93A4[0]);
    func_00505238(t, func_0045E038(D_0021F870[*on]));
}
