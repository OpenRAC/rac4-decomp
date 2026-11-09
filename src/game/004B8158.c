#include "common.h"

typedef struct Player Player;
typedef struct {
    u8 pad[0x3C];
    void (*f3C)(Player *, s32, s32, s32, s32);
} PlayerVt;
struct Player {
    u8 pad0[0x14];
    PlayerVt *vt;
    u8 pad18[0x25CC - 0x18];
    s32 state;
    u8 pad25D0[0x2F10 - 0x25D0];
    s32 slot;
};

extern s32 func_0045E038(s32);
extern s32 func_00497580(s32 *current, s32 count, void *predicate);
extern s32 func_00497628(s32 *current, s32 count, void *predicate);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004B83C8(s32 arg0);
extern void func_004B84D0(s32 arg0);
extern void func_004B85D8(s32 arg0);
extern s32 func_00505238(u32, s32);
extern s32 func_00505B20(void);
extern Player *func_00510BE8(s32 arg0);

extern s32 D_001711D0[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern u8 D_0021EE18;
extern s32 D_003D937C[];
extern s32 D_003D93E8[][13];
extern s32 D_00221790;
s32 D_0021F840 = 0;
s32 D_0021F858[2] = { 0x2F1B, 0x2F19 };

void func_004B8158(s32 arg0)
{
    s32 n;
    Player *p;
    s32 slot;
    s32 i;
    s32 *q;
    s32 s;
    s32 t;

    n = func_00505B20();
    p = func_00510BE8((D_0021EDD4 == 0 && D_0021EDD8 == 1) ? (D_0021F840 != 1) : n);
    slot = p->slot;
    if (arg0 > 0) {
        func_00497628(&D_001711D0[slot], 3, 0);
        func_00497980(0x10);
    } else if (arg0 < 0) {
        func_00497580(&D_001711D0[slot], 3, 0);
        func_00497980(0x10);
    }
    t = func_004A1A60(&D_00221790, D_003D937C[0]);
    func_00505238(t, func_0045E038(D_0021F858[D_001711D0[slot]]));
    q = D_003D93E8[D_001711D0[slot]];
    for (i = 0; i < 13; i++) {
        s = func_004A1A60(&D_00221790, i + 0xB4);
        func_00505238(s, func_0045E038(*q++));
    }
    if (D_0021EDD4 == 0 && D_0021EDD8 == 0) {
        s = func_004A1A60(&D_00221790, 0xB6);
        func_00505238(s, func_0045E038(0x3163));
    } else if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        s = func_004A1A60(&D_00221790, 0xB6);
        func_00505238(s, func_0045E038(0x3164));
    } else {
        s = func_004A1A60(&D_00221790, 0xB6);
        func_00505238(s, func_0045E038(0x3165));
    }
    func_004B84D0(0);
    func_004B83C8(0);
    func_004B85D8(0);
    if (D_0021EE18 == 0 && p->state != 0x31 && p->state != 0x98) {
        p->vt->f3C(p, 0, 1, 0, 1);
    }
}
