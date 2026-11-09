#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct {
    u128 pos;
    u128 rot;
} MsgSpawn;

typedef struct {
    f32 x;
    f32 y;
    u8 pad8[4];
    s32 c;
} MsgMove;

typedef struct {
    u8 pad0[0x10];
    u128 pos;
    u8 pad20[0x14];
    u16 flags;
    u8 pad36[0xBA];
    u128 rot;
} Moby;

typedef struct {
    u8 pad0[0x9C];
    s32 x9C;
    u8 padA0[0x580];
    u128 x620;
    u8 pad630[0x56];
    u8 x686;
} VarsT;

extern void func_L01_004B4870(Moby *);
extern void func_L01_004B57F8(Moby *);
extern void func_L01_005B00B8(Moby *, f32, f32);
extern s32 func_00481900(Moby *, s32, void *, s32, s32, s32, f32);
extern void func_00474368(Moby *, s32, s32);
extern void func_L01_005B4F98(Moby *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004B58F0();
extern void func_L01_004B5A50();

// // Switches on the second argument. 0 and 1 scale the two floats in the data and call func_L01_005B00B8,
// // func_00481900 and func_00474368 (1 first calls func_L01_004B57F8 if byte +0xC is set; 0 also copies +0xC
// // to vars+0x9C). 2 copies a qword to vars+0x620. 5 copies two qwords to moby+0x10 and moby+0xF0.
void func_L01_004B5BB8(Moby *moby, u32 msg, void *data) {
    VarsT *v = *(VarsT **)((u8 *)moby + 0xAC);

    func_L01_004B4870(moby);
    switch (msg) {
    case 1:
        if (((u8 *)data)[0xC] != 0) {
            func_L01_004B57F8(moby);
        }
        func_L01_005B00B8(moby, ((MsgMove *)data)->x * 0.020000001f, ((MsgMove *)data)->y * 0.020000001f);
        func_00481900(moby, 3, func_L01_004B58F0, 0, 0, 0, 0.0f);
        func_00474368(moby, 1, 1);
        break;
    case 0:
        func_L01_005B00B8(moby, ((MsgMove *)data)->x * 0.020000001f, ((MsgMove *)data)->y * 0.020000001f);
        func_00481900(moby, 3, func_L01_004B58F0, 0, 0, 0, 0.0f);
        v->x9C = ((MsgMove *)data)->c;
        func_00474368(moby, 1, 1);
        break;
    case 2:
        v->x620 = ((MsgSpawn *)data)->pos;
        func_00474368(moby, 0xB, 5);
        break;
    case 3:
        func_00481900(moby, 0xA, func_L01_004B5A50, 0, 0, 1, 0.0f);
        func_00474368(moby, 2, 2);
        break;
    case 5:
        moby->pos = ((MsgSpawn *)data)->pos;
        moby->rot = ((MsgSpawn *)data)->rot;
        moby->flags = (moby->flags & 0xFF7F) | 0x800;
        v->x686 = 1;
        func_L01_005B4F98(moby, 0x18, 8, 4, 0x29, 0xFFFF, 0xFFFF, -1, -1);
        func_00474368(moby, 3, 3);
        break;
    }
}
