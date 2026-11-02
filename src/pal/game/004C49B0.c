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
extern s32 func_00506BB8(void);
extern Player *func_00511CC0(s32);
extern s32 func_00498518(s32);
extern s32 func_0054BD48(void *, s32);
extern s32 func_0054B8D8(void *, s32, s32);
extern s32 func_0054BB70(void *, s32, s32);
extern void func_004985F0(s32);
void func_004C49B0(void)
{
    State *p;
    Player *player;
    s32 item;
    s32 index = func_00506BB8();
    p = &D_0030B7F8[index];
    player = func_00511CC0(index);
    item = func_00498518(p->choice);
    if (func_0054BD48(player->equipment, item) != p->desired) {
        if (p->desired)
            func_0054B8D8(player->equipment, item, p->desired);
        else
            func_0054BB70(player->equipment, item, 1);
        func_004985F0(22);
        p->flags |= 64;
    }
}
