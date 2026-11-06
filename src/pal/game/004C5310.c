#include "common.h"

typedef struct State {
    u8 prefix[0x18];
    s32 level;
} State;
extern u16 D_001F628C[];
extern u8 D_0030B7F8[];
extern s32 func_0045E478(s16 message, s16 id);
extern s32 func_00506BB8(void);
extern s32 func_00499120(s32 mode);
extern void func_004C52E0(void);
extern void func_004C4E40(void);
extern void func_004C4EF0(void);
extern void func_004C5020(void);
extern s32 func_004C4138(s32 level);
extern void func_004C45C8(s32 next);
extern void func_004C4D20(void);
extern void func_004985F0(s32 id);
extern void func_004C3EE0(s32 next);
extern void func_004C4B08(void);

void func_004C5310(void)
{
    s32 first;
    s32 last;
    State *state;

    if (D_001F628C[0] != 0) {
        func_0045E478(0x2FAF, 0x684);
        func_0045E478(0x2FB0, 0x685);
        func_0045E478(0x2FB1, 0x686);
    }
    first = 0;
    state = (State *)((u32)D_0030B7F8 + (u32)func_00506BB8() * 0x74u);
    last = 7;
    switch (func_00499120(6)) {
    case 13:
        func_004C52E0();
        break;
    case 1:
        func_004C4E40();
        break;
    case 3:
        func_004C4EF0();
        break;
    case 4:
        func_004C5020();
        break;
    case 7:
        while (first < 8 && !func_004C4138(first)) {
            first++;
        }
        if (first < state->level) {
            func_004C45C8(1);
            break;
        }
    case 2:
        func_004C4D20();
        break;
    case 8:
        while (last >= 0 && !func_004C4138(last)) {
            last--;
        }
        if (state->level < last) {
            func_004C45C8(0);
        } else {
            func_004985F0(4);
        }
        break;
    case 9:
    case 10:
        func_004C3EE0(1);
        func_004C4B08();
        break;
    case 11:
    case 12:
        func_004C3EE0(0);
        func_004C4B08();
        break;
    }
}
