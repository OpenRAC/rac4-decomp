#include "common.h"
typedef struct {
    char pad[8];
    s32 flags;
    s32 choice;
    s32 other;
    s32 desired;
    char rest[0x5C];
} State;
typedef struct {
    char pad[0x26E4];
    void *equipment;
} Player;
extern State D_0030B7F8[];
extern s32 func_00505B20(void);
extern Player *func_00510BE8(s32);
extern s32 func_004978C0(s32);
extern s32 func_0054A7E0(void *, s32);
extern s32 func_0054A370(void *, s32, s32);
extern s32 func_0054A608(void *, s32, s32);
extern void func_00497980(s32);
void func_004C3B88(void)
{
    State *p;
    Player *player;
    s32 item;
    s32 index = func_00505B20();
    p = &D_0030B7F8[index];
    player = func_00510BE8(index);
    item = func_004978C0(p->choice);
    if (func_0054A7E0(player->equipment, item) != p->desired) {
        if (p->desired)
            func_0054A370(player->equipment, item, p->desired);
        else
            func_0054A608(player->equipment, item, 1);
        func_00497980(22);
        p->flags |= 64;
    }
}
