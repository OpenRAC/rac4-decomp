#include "common.h"

typedef struct Inventory Inventory;
typedef struct Hero {
    u8 prefix[0x26E4];
    Inventory *inventory;
} Hero;
typedef struct State {
    u8 prefix[0xC];
    s32 item;
} State;

extern u8 D_0030B7F8[];
extern s32 func_00506BB8(void);
extern Hero *func_00511CC0(s32 context);
extern s32 func_00498518(s32 item);
extern s32 func_0054B0A0(Inventory *inventory, s32 upgrade);
extern s32 func_0054B6F8(s32 item, s32 upgrade);

s32 func_004C4710(s32 upgrade)
{
    s32 result = 0;
    s32 context = func_00506BB8();
    State *state = (State *)((u32)D_0030B7F8 + (u32)context * 0x74u);
    Hero *hero = func_00511CC0(context);
    s32 item = func_00498518(state->item);

    if (upgrade == 0 ||
        (func_0054B0A0(hero->inventory, upgrade) && func_0054B6F8(item, upgrade))) {
        result = 1;
    }
    return result;
}
