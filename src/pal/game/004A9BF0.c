#include "common.h"

typedef struct {
    u8 unknown0[0x70];
    s32 cost;
    s32 amount;
    s32 displayedAmount;
    u8 tail[0x3C];
} State;
typedef struct {
    u8 unknown0[0x26E4];
    void *inventory;
} Hero;
typedef struct {
    u8 unknown0[0x20];
    s8 suppressCost;
} Mode;

extern State D_00308208[];
extern s32 D_0021EE54;
extern Mode *D_0021E078;
extern s32 func_00506BB8(void);
extern s32 func_004A9450(void);
extern Hero *func_00511CC0(s32);
extern s32 func_00549580(s32);
extern s32 func_00549398(void *, s32);
extern s32 func_00549368(void *, s32);
extern void func_004A94E8(s32, s32);
extern void func_004A9718(s32, s32);

void func_004A9BF0(void)
{
    s32 index = func_00506BB8();
    s32 item = func_004A9450();
    State *state = &D_00308208[index];
    Hero *hero = func_00511CC0(index);
    s32 cost;
    s32 amount;

    if (func_00549580(item)) {
        cost = 0;
    } else {
        cost = func_00549398(hero->inventory, item);
    }
    if (D_0021EE54 == 1 && D_0021E078->suppressCost) {
        cost = 0;
    }
    if (state->cost != cost) {
        state->cost = cost;
        func_004A94E8(index, cost);
    }
    amount = func_00549368(hero->inventory, item);
    state->amount = amount;
    if (state->displayedAmount != amount) {
        state->displayedAmount = amount;
        func_004A9718(index, amount);
    }
}
