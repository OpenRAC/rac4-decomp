/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

s32 func_01F0C090(void *, s32);
extern u8 D_0019D208[];

typedef struct Drawer Drawer;
typedef struct {
    u8 pad0[0x88];
    void (*draw)(Drawer *, s32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);
} DrawerVt;
struct Drawer {
    DrawerVt *vt;
};

typedef struct Obj Obj;
typedef struct {
    u8 pad0[0x20];
    s32 (*check)(Obj *);
} ObjVt;
struct Obj {
    u8 pad0[0x4];
    s32 f4;
    u8 pad8[0x80 - 0x8];
    Drawer **drawer;
    u8 pad84[0xB0 - 0x84];
    ObjVt *vt;
    u8 padB4[0x134 - 0xB4];
    u8 f134[0x154 - 0x134];
    f32 f154;
    f32 f158;
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
    s32 f16C;
};

void func_01EF913C(Obj *obj) {
    Drawer *d = *obj->drawer;
    void *p = obj->f134;
    s32 r;
    s32 a1, a3, t0, t1, t2, t3;
    f32 x, y;
    DrawerVt *vt;
    s32 alpha;

    if (d == NULL) {
        func_01F0C090(D_0019D208, 0x87);
    }
    alpha = 0xFF;
    r = obj->vt->check(obj);
    a1 = obj->f4;
    a3 = obj->f16C;
    t0 = obj->f164;
    t1 = obj->f168;
    t2 = obj->f15C;
    t3 = obj->f160;
    x = obj->f154;
    y = obj->f158;
    vt = d->vt;
    if (r != 0) {
        vt->draw(d, a1, p, a3, t0, t1, t2, t3, x, y, 1, alpha);
    } else {
        vt->draw(d, a1, p, a3, t0, t1, t2, t3, x, y, 0, alpha);
    }
}
