#include "common.h"
typedef struct Match {
    u8 pad[6];
    s16 count, state, active;
    s16 padC, players;
} Match;
extern Match *D_00221DF0;
extern s32 D_0021DE3C, D_0021DE40, D_00221DFC;
extern void func_004DF7E0(s32, s32), func_004DFA40(void), func_004DFB00(s32, s32), func_004DFFF8(s32), func_004E03C8(void);
void func_004DFD38(void)
{
    s32 active = 0, selected, amount, i;
    s32 flag = D_00221DF0->active;
    if (flag)
        active = D_00221DF0->players >= 2;
    if (active) {
        if (D_00221DF0->state == 0)
            func_004DF7E0(flag, 0);
        else
            func_004DFA40();
        selected = D_0021DE3C == 6;
    } else
        selected = 0;
    amount = (s32)((u32)D_0021DE40 - (u32)D_00221DFC);
    if (amount >= 3)
        amount = 2;
    for (i = 0; i < D_00221DF0->count; i++) {
        func_004DFB00(i, amount);
        func_004DFFF8(i);
        if (active && i == selected)
            func_004E03C8();
    }
    D_00221DFC = D_0021DE40;
}
