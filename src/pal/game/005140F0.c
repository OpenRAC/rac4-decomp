#include "common.h"
typedef unsigned int Quad __attribute__((mode(TI)));
typedef struct Hero Hero;
typedef struct Methods {
    u8 unknown0[0x48];
    s32 (*query)(Hero *);
} Methods;
extern void func_00453F30(void *destination, const void *source, s32 size);
extern s32 func_00526388(Hero *hero);
#define FIELD(base, type, offset) (*(type *)((u32)(base) + (offset)))
void func_005140F0(Hero *hero)
{
    u8 *target = FIELD(hero, u8 *, 0x2EFC);
    u8 *snapshot = target + 0x150;
    FIELD(target, Quad, 0x150) = FIELD(hero, Quad, 0x20);
    FIELD(snapshot, Quad, 0x10) = FIELD(hero, Quad, 0x30);
    FIELD(snapshot, Quad, 0x20) = FIELD(hero, Quad, 0x40);
    FIELD(snapshot, Quad, 0x30) = FIELD(hero, Quad, 0x50);
    FIELD(target, Quad, 0x190) = FIELD(hero, Quad, 0xA0);
    FIELD(target, Quad, 0x1A0) = FIELD(hero, Quad, 0xB0);
    FIELD(target, Quad, 0x1B0) = FIELD(hero, Quad, 0xF0);
    FIELD(target, Quad, 0x1C0) = FIELD(hero, Quad, 0x190);
    FIELD(target, Quad, 0x1D0) = FIELD(hero, Quad, 0x270);
    FIELD(target, Quad, 0x1E0) = FIELD(hero, Quad, 0x1D90);
    FIELD(target, Quad, 0x1F0) = FIELD(hero, Quad, 0xD0);
    FIELD(target, Quad, 0x230) = FIELD(hero, Quad, 0x19A0);
    func_00453F30(target + 0x200, (u8 *)hero + 0x1970, 0x30);
    FIELD(snapshot, void *, 0xF0) = FIELD(hero, void *, 0x2EF0);
    FIELD(snapshot, s32, 0xF4) = FIELD(hero, Methods *, 0x14)->query(hero);
    FIELD(snapshot, s32, 0xF8) = FIELD(hero, s32, 0x2EC);
    FIELD(snapshot, s32, 0xFC) = FIELD(hero, s32, 0x2DDC);
    if (FIELD(hero, s32, 0x25CC) == 0x99 && FIELD(hero, s32, 0x25D8) == 0x76)
        FIELD(snapshot, s32, 0x100) = 0x76;
    else
        FIELD(snapshot, s32, 0x100) = FIELD(hero, s32, 0x25CC);
    FIELD(snapshot, s32, 0x104) = FIELD(hero, s32, 0x25D4);
    FIELD(snapshot, s32, 0x108) = FIELD(hero, s32, 0x25D8);
    FIELD(snapshot, f32, 0x10C) = FIELD(hero, f32, 0x1B0);
    FIELD(snapshot, f32, 0x110) = FIELD(hero, f32, 0x1B4);
    FIELD(snapshot, f32, 0x114) = FIELD(hero, f32, 0x2CC);
    FIELD(snapshot, f32, 0x118) = FIELD(hero, f32, 0x2E0);
    FIELD(snapshot, s32, 0x11C) = FIELD(hero, s32, 0x2F0);
    FIELD(snapshot, u16, 0x120) = FIELD(hero, u16, 0x2FC);
    FIELD(snapshot, u16, 0x122) = FIELD(hero, u16, 0x2FE);
    FIELD(snapshot, u16, 0x124) = FIELD(hero, u16, 0x2F8);
    FIELD(snapshot, u16, 0x126) = FIELD(hero, u16, 0x5F4);
    FIELD(snapshot, u16, 0x128) = FIELD(hero, u16, 0x1D1E);
    FIELD(snapshot, u8, 0x12A) = FIELD(hero, u8, 0x1D0E);
    if (FIELD(hero, s32, 0x25CC) != 0x31)
        FIELD(snapshot, u8, 0x12B) = 0;
    FIELD(snapshot, u8, 0x12C) = 1;
    FIELD(snapshot, u8, 0x133) = FIELD(hero, u8, 0x266A);
    FIELD(snapshot, u8, 0x12D) = func_00526388(hero);
    FIELD(snapshot, u8, 0x12E) = FIELD(hero, u8, 0x435);
    FIELD(snapshot, u8, 0x12F) = FIELD(hero, u8, 0x439);
    FIELD(snapshot, u8, 0x130) = FIELD(hero, u8, 0x436);
    FIELD(snapshot, u8, 0x131) = FIELD(hero, u8, 0x43A);
    FIELD(snapshot, u8, 0x132) = FIELD(hero, u8, 0x434);
    FIELD(snapshot, void *, 0x134) = FIELD(hero, void *, 0x2F00);
    FIELD(snapshot, s32, 0x144) = FIELD(hero, s16, 0x3D8);
    FIELD(snapshot, f32, 0x148) = FIELD(hero, f32, 0x1DC4);
    if (FIELD(hero, s32, 0x25D4) == 0xE) {
        FIELD(snapshot, s32, 0x138) = FIELD(hero, s32, 0x1ED4);
        FIELD(snapshot, f32, 0x13C) = FIELD(hero, f32, 0x1EEC);
        FIELD(snapshot, f32, 0x140) = FIELD(hero, f32, 0x1EE0);
    }
    if (FIELD(hero, s32, 0x25D4) == 0xD && FIELD(hero, s32, 0x1AE0) == 0) {
        if (FIELD(hero, s32, 0x1EA4) != 0)
            FIELD(snapshot, s32, 0x138) = FIELD(hero, s32, 0x1EA4);
    }
    if (FIELD(hero, s32, 0x25D4) == 0x1A) {
        FIELD(snapshot, s32, 0x150) = FIELD(hero, s32, 0x560);
        FIELD(snapshot, s32, 0x14C) = FIELD(hero, s32, 0x570);
    } else if (FIELD(hero, s32, 0x25D4) == 0xF) {
        FIELD(snapshot, s32, 0x150) = FIELD(hero, s32, 0x4A0);
        FIELD(snapshot, s32, 0x14C) = FIELD(hero, s32, 0x4B0);
    } else {
        FIELD(snapshot, s32, 0x150) = 0;
        FIELD(snapshot, s32, 0x14C) = 0;
    }
}
#undef FIELD
