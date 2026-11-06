#include "common.h"

typedef struct State {
    u8 prefix[0x38];
    s32 resource;
    u8 rest[0x28];
} State;
typedef struct Resource {
    s32 type, id;
    u32 value;
    u32 rest[3];
} Resource;
typedef struct Player {
    u8 prefix[0x26E4];
    void *settings;
} Player;
typedef struct Item {
    u8 prefix[0x36];
    u16 value;
} Item;
extern u8 D_0030EAA0[];
extern s32 D_00221A20;
typedef struct Widgets {
    u8 prefix[0x20];
    s32 first, second, third, fourth;
} Widgets;
extern Widgets D_003D27A8;
extern void func_004999D0(Resource *);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_005063C0(s32, u32);
extern s32 func_00506590(s32, u32);
extern s32 func_00506000(s32, s32);
extern s32 func_004CD818(void);
extern Player *func_00511CC0(s32);
extern s32 func_0054A308(void *, s32);
extern Item *func_0054A290(s32, s32);

void func_004CCA38(s32 context)
{
    Resource descriptor;
    State *state = (State *)((u32)D_0030EAA0 + (u32)context * 100);
    Widgets *items = &D_003D27A8;
    Player *player;
    descriptor.type = 5;
    descriptor.id = state->resource;
    func_004999D0(&descriptor);
    func_005063C0(func_004A2798(&D_00221A20, items->first), 0x80808080);
    func_00506590(func_004A2798(&D_00221A20, items->first), descriptor.value);
    func_00506000(func_004A2798(&D_00221A20, items->first), 1);
    func_005063C0(func_004A2798(&D_00221A20, items->second), 0x80808080);
    {
        s32 handle = func_004A2798(&D_00221A20, items->second);
        func_00506590(handle, func_004CD818());
    }
    func_00506000(func_004A2798(&D_00221A20, items->second), 1);
    player = func_00511CC0(context);
    if (func_0054A308(player->settings, 17)) {
        s32 handle;
        func_005063C0(func_004A2798(&D_00221A20, items->third), 0x80808080);
        handle = func_004A2798(&D_00221A20, items->third);
        func_00506590(handle, func_0054A290(17, 0)->value);
        func_00506000(func_004A2798(&D_00221A20, items->third), 1);
    } else {
        func_00506000(func_004A2798(&D_00221A20, items->third), 0);
    }
    if (func_0054A308(player->settings, 18)) {
        s32 handle;
        func_005063C0(func_004A2798(&D_00221A20, 51), 0x80808080);
        handle = func_004A2798(&D_00221A20, 51);
        func_00506590(handle, func_0054A290(18, 0)->value);
        func_00506000(func_004A2798(&D_00221A20, 51), 1);
    } else {
        func_00506000(func_004A2798(&D_00221A20, D_003D27A8.fourth), 0);
    }
}
