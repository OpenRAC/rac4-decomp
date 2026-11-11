#include "common.h"
typedef struct { s32 a; s32 b; u8 c; u8 pad[3]; } Entry;
typedef struct { s32 a; s32 b; s32 id; } Slot;
typedef struct { s32 value; u8 pad[28]; } Item;
extern Entry D_003D92A0[];
extern Slot D_003D1A78[];
extern Item D_003D8500[];
extern s32 D_002216B0;
extern u8 D_003092A0[];
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004AE820(s32);
extern void func_00504F68(s32, s32);
extern s32 func_005054F8(u32 id, s32 amount);
extern s32 func_00505B20(void);

void func_004AEBF8(void)
{
    s32 *flags = (s32 *)(D_003092A0 + func_00505B20() * 0x64);
    s32 i;

    if (D_0021EDD4 != 0)
        return;
    if (D_0021EDD8 != 0)
        return;
    for (i = 0; i < 4; i++) {
        if (func_004AE820(i)) {
            func_00504F68(func_004A1A60(&D_002216B0, D_003D1A78[i].id), flags[10 + i] != 0);
        } else {
            Item *item = &D_003D8500[D_003D92A0[i].a];
            func_005054F8(func_004A1A60(&D_002216B0, D_003D1A78[i].id), item->value);
            func_00504F68(func_004A1A60(&D_002216B0, D_003D1A78[i].id), 1);
        }
    }
}
