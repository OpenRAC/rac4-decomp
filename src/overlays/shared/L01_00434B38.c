#include "common.h"

typedef struct Item { u8 pad0[8]; u8 f8; u8 pad9[3]; s32 fC; u8 pad10[0x2B0]; } Item;
typedef struct State {
    u8 pad0[0x3C];
    u8 *f3C;
    f32 f40;
    u8 pad44[0xC];
    u8 f50[8];
    s32 f58;
    u8 pad5C[4];
    Item *items[3];
    u8 pad6C[0x88];
    Item first[3];
} State;

extern u8 D_00222B28;
extern u8 D_003B1ED0[];
extern void func_00452A98(u8 *, void *, s32, s32, s32, s32, s32);
extern void func_004526E0(u8 *, void *, void *, s32);
extern void func_L01_00434A20(f32, void *);

void func_L01_00434B38(u8 *obj) {
    State *s = *(State **)(obj + 0xAC);
    Item *it;
    Item **slot;
    s32 i;
    u8 *q;
    s->f40 = 0.1f;
    *(s32 *)((u8 *)s + 0xF4) = 3;
    it = (Item *)((u8 *)s + 0x110);
    slot = s->items;
    for (i = 2; i >= 0; i--) {
        *slot = it;
        it->f8 = 0;
        it = (Item *)((u8 *)it + 0x2C0);
        (*slot)->fC = 0;
        slot++;
    }
    q = s->f50;
    func_00452A98(&D_00222B28, q, 0xB, 0x7F7F7F7F, 0x7F7F2000, 0x7F5F3F3F, 0x7F4F1000);
    s->f58 = 0;
    s->f3C = D_003B1ED0;
    func_004526E0(&D_00222B28, q, D_003B1ED0, 1);
    func_L01_00434A20(s->f40, obj);
}
