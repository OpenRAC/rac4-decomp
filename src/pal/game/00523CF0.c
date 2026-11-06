#include "common.h"
typedef struct Hero Hero;
typedef struct Vtable {
    u8 pad[0x4C];
    s32 (*inventory)(Hero *);
} Vtable;
struct Hero {
    u8 pad0[0x14];
    Vtable *vtable;
    u8 pad1[0x22F0 - 0x18];
    void *equipped;
    u8 pad2[0x2318 - 0x22F4];
    s32 current;
    u8 pad3[0x266D - 0x231C];
    u8 active;
    u8 pad4[0x26E4 - 0x266E];
    void *inventory;
    u8 pad5[0x2F14 - 0x26E8];
    s32 player;
    u8 pad6[0xC];
    f32 health;
};
typedef struct Mode {
    u8 pad[0x32];
    u8 active;
} Mode;
extern s32 D_0021EE54;
extern Mode *D_0021E078;
extern void func_00523C28(Hero *, s32);
extern void func_0054A360(void *, s32, s32, s32, s32);
extern void func_0054A9C0(void *, s32, void *);
extern void func_00548F88(s32, s32, s32);
void func_00523CF0(Hero *h, s32 item, s32 amount, s32 value)
{
    func_00523C28(h, item);
    func_0054A360(h->inventory, item, amount, 1, 0);
    if (D_0021EE54 == 1 && D_0021E078->active && h->player == 1 && h->health == 200.0f) {
        void *equipped = 0;
        if (h->current == item)
            equipped = h->equipped;
        func_0054A9C0(h->inventory, item, equipped);
    }
    if (h->active)
        func_00548F88(h->vtable->inventory(h), item, value);
}
