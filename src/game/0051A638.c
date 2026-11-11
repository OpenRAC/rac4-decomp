#include "common.h"
typedef struct Hero Hero;
typedef struct HeroMethods {
    u8 unknown0[0x4C];
    s32 (*context)(Hero *hero);
} HeroMethods;
extern s32 D_0021EDD4;
extern u8 *D_0021DFF0;
extern void func_00548FD8(void *inventory, s32 retained, s32 reset);
extern void func_00525C58(Hero *hero);
extern void func_004A7C50(s32 context);
extern void func_004A7D48(s32 context);
extern void func_00522AF8(Hero *hero, s32 item, s32 mode, s32 slot);
extern void func_00548DF8(void *inventory, s32 item, s32 level, s32 force, s32 skip_existing);
#define AT(type, offset) (*(type *)((u32)hero + (offset)))
void func_0051A638(Hero *hero)
{
    s32 *row, *a, *b, *c, *d, *e;
    s32 i;
    func_00548FD8(AT(void *, 0x26E4), 1, D_0021EDD4 != 1);
    func_00525C58(hero);
    if (AT(u8, 0x266D)) {
        func_004A7C50(AT(HeroMethods *, 0x14)->context(hero));
        func_004A7D48(AT(HeroMethods *, 0x14)->context(hero));
    }
    e = (s32 *)((u32)hero + 0x26BC);
    d = (s32 *)((u32)hero + 0x2674);
    c = (s32 *)((u32)hero + 0x26A4);
    b = (s32 *)((u32)hero + 0x268C);
    a = (s32 *)((u32)hero + 0x24B0);
    row = (s32 *)((u32)hero + 0x2318);
    for (i = 5; i >= 0; i--) {
        *row = 0;
        *a++ = 0;
        row += 0x14;
        *b++ = 0;
        *c++ = 0;
        *d++ = 0;
        *e++ = 0;
    }
    AT(u8, 0x266C) = 0;
    if (D_0021EDD4 == 1) {
        func_00522AF8(hero, 0x12, 0, -1);
        func_00548DF8(AT(void *, 0x26E4), 0xE, 0, 0, 0);
        if (*(s8 *)(D_0021DFF0 + 9) != 0 && D_0021DFF0[0x2A] == 1)
            func_00522AF8(hero, 0xD, 0, -1);
    }
}
#undef AT
