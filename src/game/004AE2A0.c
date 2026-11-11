#include "common.h"
typedef struct { s32 a; s32 b; s32 id; } Slot;
extern Slot D_003D1A78[];
extern s32 D_002216B0;
extern u8 D_003092A0[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021F73C;
s32 D_0021F728[2] = { 13, 12 };
extern u8 func_00498100(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004AF508(void);
extern void func_00504F68(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 func_00548DA0(s32, s32);

void func_004AE2A0(void)
{
    s32 ctx = func_00505B20();
    f32 *entry = (f32 *)(D_003092A0 + ctx * 0x64);
    u8 *obj;
    s32 i;
    f32 f;

    func_004AF508();
    entry[23] = 2.0f;
    entry[24] = 1.0f;
    *(s32 *)entry = 0;
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        f = (u8)(func_00498100(ctx) ^ 1);
    } else {
        f = 1.0f;
    }
    entry[2] = f;
    D_0021F73C = 0x1F;
    if (D_0021EDD4 != 0)
        return;
    if (D_0021EDD8 != 1)
        return;
    obj = func_00510BE8(func_00505B20());
    for (i = 0; i < 4; i++) {
        if (func_00548DA0(*(s32 *)(obj + 0x26E4), D_0021F728[i])) {
            s32 id = func_004A1A60(&D_002216B0, D_003D1A78[i].id);
            func_005054F8(id, *(u16 *)((u8 *)func_00548D28(D_0021F728[i], 0) + 0x36));
            func_00504F68(func_004A1A60(&D_002216B0, D_003D1A78[i].id), 1);
        } else {
            func_00504F68(func_004A1A60(&D_002216B0, D_003D1A78[i].id), 0);
        }
    }
}
