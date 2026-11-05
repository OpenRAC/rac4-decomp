#include "common.h"

typedef struct State {
    u8 prefix[0x14];
    s32 level;
} State;
extern u16 D_001F6244[];
extern u8 D_0030B7F8[];
extern s32 func_0045E478(s16 message, s16 id);
extern s32 func_00506BB8(void);
extern s32 func_00499120(s32 mode);
extern void func_004C52E0(void);
extern void func_004C49B0(void);
extern s32 func_004C4710(s32 level);
extern void func_004C4948(s32 next);
extern void func_004C4D20(void);
extern void func_004985F0(s32 id);
extern void func_004C3EE0(s32 next);
extern void func_004C4A60(void);

void func_004C54C0(void)
{
    s32 first;
    s32 last;
    State *state;

    if (D_001F6244[0] != 0) {
        func_0045E478(0x2FA8, 0x67D);
        func_0045E478(0x2FA9, 0x67E);
        func_0045E478(0x2FAA, 0x67F);
        func_0045E478(0x2966, 0x2DD);
    }
    first = 0;
    state = (State *)((u32)D_0030B7F8 + (u32)func_00506BB8() * 0x74u);
    last = 9;
    switch (func_00499120(6)) {
    case 13:
        func_004C52E0();
        break;
    case 1:
        func_004C49B0();
    case 2:
    refresh:
        func_004C4D20();
        break;
    case 7:
        while (first < 9 && !func_004C4710(first)) {
            first++;
        }
        if (first < state->level) {
            func_004C4948(1);
        } else {
            goto refresh;
        }
        break;
    case 8:
        while (last >= 0 && !func_004C4710(last)) {
            last--;
        }
        if (state->level < last) {
            func_004C4948(0);
        } else {
            func_004985F0(4);
        }
        break;
    case 9:
    case 10:
        func_004C3EE0(1);
        func_004C4A60();
        break;
    case 11:
    case 12:
        func_004C3EE0(0);
        func_004C4A60();
        break;
    }
}
