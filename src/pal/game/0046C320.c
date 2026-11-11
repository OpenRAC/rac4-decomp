#include "common.h"

typedef struct Anim {
    u8 pad0[0x10];
    u8 x10;
    u8 x11;
    u8 x12;
} Anim;

typedef struct Sub98 {
    s16 x0;
    s16 x2;
} Sub98;

typedef struct Cls {
    u8 pad0[6];
    u8 x6;
    u8 pad7;
    u8 x8;
    u8 pad9;
    u8 xA;
    u8 padB;
    u8 xC;
    u8 padD;
    u8 xE;
    u8 xF;
    Sub98 *x10;
    u8 pad14[8];
    s32 *x1C;
    u8 pad20[4];
    f32 x24;
    u8 pad28[0x18];
    s32 x40;
    u16 x44;
    u8 pad46;
    u8 x47;
    Anim *x48;
} Cls;

typedef struct Moby {
    u8 pad0[0x20];
    u8 x20;
    u8 x21;
    u8 x22;
    u8 x23;
    Cls *x24;
    u8 pad28[4];
    u8 x2C;
    u8 x2D;
    u16 x2E;
    u8 pad30[4];
    u16 x34;
    u16 x36;
    u8 pad38[8];
    Anim *x40;
    u8 pad44[4];
    f32 x48;
    s16 x4C;
    u8 pad4E[6];
    u8 x54;
    u8 x55;
    u8 x56;
    u8 x57;
    s32 x58;
    u8 pad5C[4];
    s32 x60;
    u8 x64;
    u8 x65;
    u8 x66;
    u8 pad67[5];
    u8 x6C;
    u8 x6D;
    s16 x6E;
    f32 x70;
    u8 pad74[2];
    u8 x76;
    u8 x77;
    s32 x78;
    s32 x7C;
    u8 pad80[0x14];
    s16 x94;
    u8 pad96[2];
    Sub98 *x98;
    u8 pad9C[8];
    u8 xA4;
    u8 xA5;
    u8 xA6;
    u8 xA7;
    s32 xA8;
    u8 padAC[0x10];
    s16 xBC;
} Moby;

extern u8 D_00249450[];
extern s16 D_00249170[];
extern s32 D_0024BC50[];
extern s32 D_00248CC0[];
extern Cls *D_00248900[];

void func_004701A8(void);
void func_0046FD28(Moby *m);
void func_00453E20(void *p, s32 v, s32 n);
void func_0046E380(Moby *m);
void func_00470088(Moby *m);
void func_0046F6B8(Moby *m);

// Resets a moby slot for class id: clears it, keeps +0x2D, then fills the defaults from the class tables.
void func_0046C320(Moby *m, s32 id, s32 flag) {
    s32 ff;
    u8 keep;
    s32 t;
    Cls *c;
    Cls *c2;
    Cls *c3;
    Anim *a;
    u8 e;

    if (flag == 0 && m->x58 != 0) {
        func_004701A8();
        func_0046FD28(m);
    }
    ff = 0xFF;
    if (m->x20 == ff) {
        m->x2D = 0;
    }
    keep = m->x2D;
    func_00453E20(m, 0, 0x100);
    m->x2D = keep;
    t = D_00249450[id];
    m->xBC = id;
    m->x2C = ff;
    m->x21 = ff;
    m->x56 = ff;
    m->x64 = ff;
    m->x65 = ff;
    m->x6D = ff;
    m->x94 = 0;
    m->x6C = 0;
    m->x22 = t;
    m->x23 = 0x80;
    m->xA6 = 0x80;
    m->x2E = 0x7F80;
    m->x6E = -1;
    m->xA7 = 0x80;
    m->xA4 = 0x7F;
    m->xA5 = 0x7F;
    func_0046E380(m);
    if (D_00249170[m->x22] != id) {
        m->x24 = 0;
        m->x34 |= 0x45;
        m->x98 = 0;
        m->xA8 = D_0024BC50[m->x22];
        if (m->xA8 == 0) {
            m->x34 |= 2;
        }
        return;
    }
    m->xA8 = D_00248CC0[m->x22];
    if (m->xA8 == 0) {
        m->x34 |= 2;
    }
    c = D_00248900[m->x22];
    m->x24 = c;
    e = c->xE;
    m->x64 = e;
    m->x34 |= c->x44;
    m->x98 = c->x10;
    m->x70 = c->x24;
    if (c->xA != 0 && (s8)e >= 0) {
        m->x65 = e * 2;
    }
    m->x4C = 1;
    m->x48 = 1.0f;
    m->x57 = m->x24->x8;
    if (m->x57 != 0) {
        func_00470088(m);
        c2 = m->x24;
        if (c2->x1C == 0 || *c2->x1C == 0) {
            if (m->x98 == 0 || m->x98->x2 == 0) {
                m->x55 |= 0x40;
            }
        }
    } else {
        m->x48 = 0.0f;
        m->x34 |= 0x40;
    }
    c2 = m->x24;
    if (c2->x40 != 0) {
        m->x34 |= 0x10;
        m->x60 = c2->x40;
    }
    if (m->x24->xF != 0) {
        m->x76 = 0x18;
        m->x34 |= 0x400;
        m->x78 = 0;
        m->x7C = 0;
        m->x77 = 0;
    }
    if (m->x24->x6 != 0) {
        m->x66 = 0x18;
    }
    if (m->x24->x48 != 0) {
        a = m->x24->x48;
        m->x40 = a;
        m->x54 = 0;
        m->x6C = a->x12;
        m->x6D = a->x11;
        if (a->x10 >= 2) {
            m->x34 &= 0xFFFD;
        }
        c3 = m->x24;
        if (c3->xC == 1) {
            if (c3->x48->x10 < 2) {
                m->x48 = 0.0f;
                if (*(s8 *)&c3->x48->x11 < 0) {
                    m->x34 |= 0x40;
                }
            } else if (m->xA8 == 0) {
                m->x48 = 0.83333331f;
            }
        }
    }
    if (m->x58 != 0) {
        func_0046F6B8(m);
    }
    m->x36 |= m->x24->x47;
}
