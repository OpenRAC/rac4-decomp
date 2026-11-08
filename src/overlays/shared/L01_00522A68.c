#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[675 - 576];
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Ent003EC730;
typedef struct {
    u8 pad0[0x7D];
    u8 f7D;
    s16 f7E;
    u8 pad80[0x86 - 0x80];
    s16 f86;
    u8 pad88[0x94 - 0x88];
    s32 w94;
} Obj_003EC990;
typedef struct {
    u8 pad0[0xFC];
    s32 xFC;
    s32 x100;
} Sub_003EC990;
extern Ent003EC730 D_00230280[];

/* from rac3-decomp's func_L01_003EC990, constants adapted */
void func_L01_00522A68(Obj_003EC990 *obj) {
    u8 *e = (u8 *)D_00230280 + obj->w94 * 0x470;
    Sub_003EC990 *s = (Sub_003EC990 *)(e + 0x150);
    if (s->xFC != obj->f86 && s->x100 != 6) {
        obj->f7D = 0;
        obj->f7E = 3;
    }
}
