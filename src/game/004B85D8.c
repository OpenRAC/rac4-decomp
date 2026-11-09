#include "common.h"

typedef struct {
    u8 prefix[0x2F10];
    s32 slot;
} Player;
extern s32 func_00505B20(void);
extern Player *func_00510BE8(s32 arg0);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00497AE0(s32, s32, s32, f32, f32);
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
s32 D_0021F840 = 0;
extern s32 D_001711D0[];
extern struct { u8 pad[0x78]; s32 a[1][4]; } D_00171D38;
extern s32 D_00171EF0[][10];
extern s32 D_00221790;

void func_004B85D8(s32 arg0)
{
    s32 slot;
    s32 v;
    s32 a;
    s32 b;
    s32 n;

    n = func_00505B20();
    slot = func_00510BE8((D_0021EDD4 == 0 && D_0021EDD8 == 1) ? (D_0021F840 != 1) : n)->slot;
    if (arg0) {
        if ((u32)(D_00171EF0[D_001711D0[slot]][slot] += arg0 * 4) > 64) {
            func_00497980(4);
        } else {
            func_00497980(0x11);
        }
        v = D_00171EF0[D_001711D0[slot]][slot];
        if (v > 64) {
            v = 64;
        }
        if (v < 0) {
            v = 0;
        }
        D_00171EF0[D_001711D0[slot]][slot] = v;
        D_00171D38.a[D_001711D0[slot]][slot] = v;
    }
    a = func_004A1A60(&D_00221790, 0x12);
    b = func_004A1A60(&D_00221790, 0x17);
    func_00497AE0(a, b, 0, D_00171EF0[D_001711D0[slot]][slot] * 0.015625f, 0.0f);
}
