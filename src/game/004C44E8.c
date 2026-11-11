#include "common.h"

typedef struct State {
    u8 prefix[0x18];
    s32 level;
} State;
extern u16 D_001F620C[];
extern u8 D_0030B7F8[];
extern s32 func_0045DC60(s16 message, s16 id);
extern s32 func_00505B20(void);
extern s32 func_004983E8(s32 mode);
extern void func_004C44B8(void);
extern void func_004C4018(void);
extern void func_004C40C8(void);
extern void func_004C41F8(void);
extern s32 func_004C3310(s32 level);
extern void func_004C37A0(s32 next);
extern void func_004C3EF8(void);
extern void func_00497980(s32 id);
extern void func_004C30B8(s32 next);
extern void func_004C3CE0(void);

void func_004C44E8(void)
{
    s32 first;
    s32 last;
    State *state;

    if (D_001F620C[0] != 0) {
        func_0045DC60(0x2FAF, 0x684);
        func_0045DC60(0x2FB0, 0x685);
        func_0045DC60(0x2FB1, 0x686);
    }
    first = 0;
    state = (State *)((u32)D_0030B7F8 + (u32)func_00505B20() * 0x74u);
    last = 7;
    switch (func_004983E8(6)) {
    case 13:
        func_004C44B8();
        break;
    case 1:
        func_004C4018();
        break;
    case 3:
        func_004C40C8();
        break;
    case 4:
        func_004C41F8();
        break;
    case 7:
        while (first < 8 && !func_004C3310(first)) {
            first++;
        }
        if (first < state->level) {
            func_004C37A0(1);
            break;
        }
    case 2:
        func_004C3EF8();
        break;
    case 8:
        while (last >= 0 && !func_004C3310(last)) {
            last--;
        }
        if (state->level < last) {
            func_004C37A0(0);
        } else {
            func_00497980(4);
        }
        break;
    case 9:
    case 10:
        func_004C30B8(1);
        func_004C3CE0();
        break;
    case 11:
    case 12:
        func_004C30B8(0);
        func_004C3CE0();
        break;
    }
}
