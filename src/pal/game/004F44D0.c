#include "common.h"

typedef struct { s32 off; s32 sz; } E_4F44D0;
typedef struct { u8 pad0[0xA8]; s32 fA8; s32 fAC; u8 padB0[0x30]; s32 fE0[0x44]; } S_4F44D0;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_4F44D0;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 pad14[0xC]; H_4F44D0 *f20; } T_4F44D0;
extern S_4F44D0 D_00237100;
extern T_4F44D0 D_0023AC00;
extern s32 D_00221F28;
extern void func_00453E20();

/* PAL: from rac3-decomp's func_003BC698 */
void func_004F44D0(s32 a) {
    H_4F44D0 *h;
    u8 *e;
    E_4F44D0 *p;
    s32 i;
    s32 b;
    s32 v;
    T_4F44D0 *s;
    func_00453E20(&D_00237100, 0, 0x230);
    v = D_00221F28;
    s = &D_0023AC00;
    D_00237100.fAC = s->fC + v;
    D_00237100.fA8 = s->f10 + v;
    h = s->f20;
    e = (u8 *)h + h->f8 + h->tbl[a];
    b = (s32)e + 0x800;
    p = (E_4F44D0 *)e;
    for (i = 0; i < 0x44 && p->sz != 0; i++, p++) {
        D_00237100.fE0[i] = b + p->off;
    }
}
