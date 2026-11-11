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
extern s32 D_00221920;
typedef struct Widgets {
    u8 prefix[0x20];
    s32 first, second, third, fourth;
} Widgets;
extern Widgets D_003D2738;
extern void func_00498C98(Resource *);
extern s32 func_004A1A60(s32 *, s32);
extern s32 func_00505328(s32, u32);
extern s32 func_005054F8(s32, u32);
extern s32 func_00504F68(s32, s32);
extern s32 func_004CC978(void);
extern Player *func_00510BE8(s32);
extern s32 func_00548DA0(void *, s32);
extern Item *func_00548D28(s32, s32);

void func_004CBB98(s32 context)
{
    Resource descriptor;
    State *state = (State *)((u32)D_0030EAA0 + (u32)context * 100);
    Widgets *items = &D_003D2738;
    Player *player;
    descriptor.type = 5;
    descriptor.id = state->resource;
    func_00498C98(&descriptor);
    func_00505328(func_004A1A60(&D_00221920, items->first), 0x80808080);
    func_005054F8(func_004A1A60(&D_00221920, items->first), descriptor.value);
    func_00504F68(func_004A1A60(&D_00221920, items->first), 1);
    func_00505328(func_004A1A60(&D_00221920, items->second), 0x80808080);
    {
        s32 handle = func_004A1A60(&D_00221920, items->second);
        func_005054F8(handle, func_004CC978());
    }
    func_00504F68(func_004A1A60(&D_00221920, items->second), 1);
    player = func_00510BE8(context);
    if (func_00548DA0(player->settings, 17)) {
        s32 handle;
        func_00505328(func_004A1A60(&D_00221920, items->third), 0x80808080);
        handle = func_004A1A60(&D_00221920, items->third);
        func_005054F8(handle, func_00548D28(17, 0)->value);
        func_00504F68(func_004A1A60(&D_00221920, items->third), 1);
    } else {
        func_00504F68(func_004A1A60(&D_00221920, items->third), 0);
    }
    if (func_00548DA0(player->settings, 18)) {
        s32 handle;
        func_00505328(func_004A1A60(&D_00221920, 51), 0x80808080);
        handle = func_004A1A60(&D_00221920, 51);
        func_005054F8(handle, func_00548D28(18, 0)->value);
        func_00504F68(func_004A1A60(&D_00221920, 51), 1);
    } else {
        func_00504F68(func_004A1A60(&D_00221920, D_003D2738.fourth), 0);
    }
}
