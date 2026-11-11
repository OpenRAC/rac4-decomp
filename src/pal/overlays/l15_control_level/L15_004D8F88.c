#include "common.h"

typedef struct Moby Moby;

typedef struct Vars {
    u8 pad0[0x104];
    Moby *x104;
} Vars;

struct Moby {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x10];
    u8 x31;
    u8 pad32[2];
    u16 x34;
    u8 pad36[0x33];
    u8 x69;
    u8 pad6A[0x42];
    Vars *xAC;
};

s32 D_002221EC = 0;
extern s32 D_0021DE3C;
extern s32 D_0021DE40;
extern int D_0022251C;

extern void func_L15_004D9150(Moby *m);
extern void func_00461A80(s32 h);
extern s32 func_L00_005A1078(void);
extern void func_L15_004D8C50(Moby *m, s32 a, s32 b);
extern void func_L15_004D9DE8(Moby *m);
extern void func_L15_004DAB20(Moby *m);
extern void func_L15_004E5878(Moby *m, s32 a);
extern void func_L15_004DB440(Moby *m);
extern void func_L15_004DDF70(Moby *m);
extern void func_L15_004DD870(Moby *m);
extern void func_L15_004D9D28(Moby *m);
extern void func_00449A28(void *, void (*)(), Moby *);
extern void func_L15_004E0BF8();
extern void func_L15_004E15C8();
extern void func_L15_004E1B38();

// Per-frame update of a moby: hides it and its child at vars+0x104 while func_L00_005A1078 is set or the D_0021DE3C/D_0021DE40 checks fail, otherwise shows them and runs the action for m->x69.
void func_L15_004D8F88(Moby *m) {
    Vars *v;
    Vars *w;

    func_L15_004D9150(m);
    if (D_002221EC != 0 && m->x20 != 3) {
        func_00461A80(D_002221EC);
        D_002221EC = 0;
    }
    if (func_L00_005A1078() != 0 || D_0021DE3C == 2 || D_0021DE3C == 1 || D_0021DE40 < 50) {
        m->x31 = 0;
        m->x34 |= 1;
        v = m->xAC;
        v->x104->x34 |= 1;
        v->x104->x31 = 0;
        func_L15_004D8C50(m, 0, 1);
        func_L15_004D9DE8(m);
        func_L15_004DAB20(m);
        return;
    }
    m->x31 = 1;
    m->x34 &= 0xFFFE;
    w = m->xAC;
    w->x104->x34 &= 0xFFFE;
    w->x104->x31 = 1;
    switch (m->x69) {
    case 1:
        func_L15_004D8C50(m, 1, 1);
        func_L15_004E5878(m, 1);
    case 3:
        func_L15_004DB440(m);
        break;
    case 2:
        func_L15_004DDF70(m);
        break;
    case 4:
        func_L15_004DD870(m);
        break;
    }
    func_L15_004D9D28(m);
    func_00449A28(&D_0022251C, func_L15_004E0BF8, m);
    func_00449A28(&D_0022251C, func_L15_004E15C8, m);
    func_00449A28(&D_0022251C, func_L15_004E1B38, m);
}
