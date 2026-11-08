#include "common.h"

typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0xA8]; s32 fA8; s32 fAC; u8 padB0[0x30]; s32 fE0[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 pad14[0xC]; H_3B71B8 *f20; } S_227600_3B71B8;
extern S_225780_3B71B8 D_00237000;
extern S_227600_3B71B8 D_0023AB00;
extern s32 D_00221E28;
extern void func_00453608();

/* from rac3-decomp's func_003BC698 */
void func_004F3468(s32 a) {
    H_3B71B8 *h;
    u8 *e;
    E_3B71B8 *p;
    s32 i;
    s32 b;
    s32 v;
    S_227600_3B71B8 *s;
    func_00453608(&D_00237000, 0, 0x230);
    v = D_00221E28;
    s = &D_0023AB00;
    D_00237000.fAC = s->fC + v;
    D_00237000.fA8 = s->f10 + v;
    h = s->f20;
    e = (u8 *)h + h->f8 + h->tbl[a];
    b = (s32)e + 0x800;
    p = (E_3B71B8 *)e;
    for (i = 0; i < 0x44 && p->sz != 0; i++, p++) {
        D_00237000.fE0[i] = b + p->off;
    }
}
