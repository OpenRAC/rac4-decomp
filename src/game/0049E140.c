#include "common.h"

extern s32 D_00307074[];
extern s32 D_00307220[];
extern s32 *D_0021DDA4;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 func_00505B20(void);
extern s32 *func_00510BE8(s32);
extern f32 func_0049B528(void *, s32);
extern void func_0049E2B8(s32);
extern void func_0049E478(s32);
extern void func_00497438(s32, s32, s32);

void func_0049E140(void) {
    s32 index = func_00505B20();
    s32 *record;
    s32 *state;

    if (index == 4) {
        record = D_00307074;
    } else {
        record = D_00307220 + index * 0x80;
    }
    state = func_00510BE8(index);
    if (func_0049B528(record + 1, ((u8 *)record)[0]) == 0.0f) {
        if (((u8 *)record)[0] != 0 && ((u8 *)record)[0x1C] == 0) {
            func_0049E2B8(index);
        }
    } else {
        func_0049E478(index);
    }
    if (*(f32 *)(record + 1) == 0.0f) {
        return;
    }
    if (index == 4) {
        for (index = 0; index < *D_0021DDA4; index++) {
            func_00497438(index, 3, 4);
        }
        return;
    }
    *(s16 *)((u8 *)state + 0x3BA) = 3;
    func_00497438(index, 3, 4);
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
        func_00497438((u32)index < 1, 3, 4);
    }
}
