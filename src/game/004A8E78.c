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

extern State D_00308108[];
extern s32 D_0021EDD4;
extern Mode *D_0021DFF0;
extern s32 func_00505B20(void);
extern s32 func_004A86E0(void);
extern Hero *func_00510BE8(s32);
extern s32 func_00548018(s32);
extern s32 func_00547E30(void *, s32);
extern s32 func_00547E00(void *, s32);
extern void func_004A8778(s32, s32);
extern void func_004A89A0(s32, s32);

void func_004A8E78(void)
{
    s32 index = func_00505B20();
    s32 item = func_004A86E0();
    State *state = &D_00308108[index];
    Hero *hero = func_00510BE8(index);
    s32 cost;
    s32 amount;

    if (func_00548018(item)) {
        cost = 0;
    } else {
        cost = func_00547E30(hero->inventory, item);
    }
    if (D_0021EDD4 == 1 && D_0021DFF0->suppressCost) {
        cost = 0;
    }
    if (state->cost != cost) {
        state->cost = cost;
        func_004A8778(index, cost);
    }
    amount = func_00547E00(hero->inventory, item);
    state->amount = amount;
    if (state->displayedAmount != amount) {
        state->displayedAmount = amount;
        func_004A89A0(index, amount);
    }
}
