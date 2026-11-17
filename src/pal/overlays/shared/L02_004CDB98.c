#include "common.h"

typedef struct Vars {
    u8 pad0[0x84];
    s16 x84;
    s16 x86;
    u8 pad88;
    u8 x89;
    u8 x8A;
} Vars;

typedef struct Moby {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0x8B];
    Vars *xAC;
} Moby;

extern s32 D_0021DE3C;
extern s32 D_0021DE98;
extern s32 D_0021EB18;
extern u16 D_001F6808[];
extern s32 D_0021E774;
extern s32 D_0021E778;

extern s32 func_L01_0058A000(void *);
extern void func_L02_004CDD50(Moby *m);
extern s32 func_00453D20(s16 *p);
extern void func_004E2EF0(s32 a, s32 b, Moby *m);
extern s32 func_L01_00589E70(Moby *m);
extern void func_00474368(Moby *m, s32 a, s32 b);
extern s32 func_0045E850(s32 id);
extern void func_L01_005DBFC8(s32 a, s32 b, s32 c, s32 d);
extern void func_L01_005DBFA0(s32 a, s32 b, s32 c);

// Per-frame update of a moby with a counter at vars+0x84: calls func_004E2EF0 at some counter values, then calls func_L01_005DBFC8 and func_L01_005DBFA0 for player 0 (and player 1 when D_0021E778 == 1).
void func_L02_004CDB98(Moby *m) {
    Vars *v;

    if (D_0021DE3C == 2) {
        return;
    }
    if (func_L01_0058A000(m) != 0) {
        return;
    }
    if (m->x20 == 0) {
        func_L02_004CDD50(m);
    }
    v = m->xAC;
    if (m->x20 == 1) {
        if (D_0021DE98 != 2 || D_0021EB18 != 4 || D_001F6808[0] != 0) {
            if (func_00453D20(&v->x84) != 0) {
                func_004E2EF0(1, 0x130, m);
            } else if ((v->x86 * 50 >= v->x84 && v->x84 % 50 == 0) || v->x84 % 3000 == 0) {
                func_004E2EF0(0, 0x130, m);
            }
        }
        if (func_L01_00589E70(m) != 0) {
            func_00474368(m, 2, -1);
        }
    }
    func_L01_005DBFC8(0, func_0045E850(0x255C), v->x89, v->x8A);
    func_L01_005DBFA0(0, func_0045E850(0x255D), v->x84);
    if (D_0021E774 == 0 && D_0021E778 == 1) {
        func_L01_005DBFC8(1, func_0045E850(0x255C), v->x89, v->x8A);
        func_L01_005DBFA0(1, func_0045E850(0x255D), v->x84);
    }
}
