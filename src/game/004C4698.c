#include "common.h"

typedef struct State {
    u8 prefix[0x14];
    s32 level;
} State;
extern u16 D_001F61C4[];
extern u8 D_0030B7F8[];
extern s32 func_0045DC60(s16 message, s16 id);
extern s32 func_00505B20(void);
extern s32 func_004983E8(s32 mode);
extern void func_004C44B8(void);
extern void func_004C3B88(void);
extern s32 func_004C38E8(s32 level);
extern void func_004C3B20(s32 next);
extern void func_004C3EF8(void);
extern void func_00497980(s32 id);
extern void func_004C30B8(s32 next);
extern void func_004C3C38(void);

void func_004C4698(void)
{
    s32 first;
    s32 last;
    State *state;

    if (D_001F61C4[0] != 0) {
        func_0045DC60(0x2FA8, 0x67D);
        func_0045DC60(0x2FA9, 0x67E);
        func_0045DC60(0x2FAA, 0x67F);
        func_0045DC60(0x2966, 0x2DD);
    }
    first = 0;
    state = (State *)((u32)D_0030B7F8 + (u32)func_00505B20() * 0x74u);
    last = 9;
    switch (func_004983E8(6)) {
    case 13:
        func_004C44B8();
        break;
    case 1:
        func_004C3B88();
    case 2:
    refresh:
        func_004C3EF8();
        break;
    case 7:
        while (first < 9 && !func_004C38E8(first)) {
            first++;
        }
        if (first < state->level) {
            func_004C3B20(1);
        } else {
            goto refresh;
        }
        break;
    case 8:
        while (last >= 0 && !func_004C38E8(last)) {
            last--;
        }
        if (state->level < last) {
            func_004C3B20(0);
        } else {
            func_00497980(4);
        }
        break;
    case 9:
    case 10:
        func_004C30B8(1);
        func_004C3C38();
        break;
    case 11:
    case 12:
        func_004C30B8(0);
        func_004C3C38();
        break;
    }
}
