#include "common.h"

extern s32 D_00307174[];
extern s32 D_00307320[];
extern s32 *D_0021DE2C;
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 func_00506BB8(void);
extern s32 *func_00511CC0(s32);
extern f32 func_0049C260(void *, s32);
extern void func_0049EFF0(s32);
extern void func_0049F1B0(s32);
extern void func_00498090(s32, s32, s32);

void func_0049EE78(void) {
    s32 index = func_00506BB8();
    s32 *record;
    s32 *state;

    if (index == 4) {
        record = D_00307174;
    } else {
        record = D_00307320 + index * 0x80;
    }
    state = func_00511CC0(index);
    if (func_0049C260(record + 1, ((u8 *)record)[0]) == 0.0f) {
        if (((u8 *)record)[0] != 0 && ((u8 *)record)[0x1C] == 0) {
            func_0049EFF0(index);
        }
    } else {
        func_0049F1B0(index);
    }
    if (*(f32 *)(record + 1) == 0.0f) {
        return;
    }
    if (index == 4) {
        for (index = 0; index < *D_0021DE2C; index++) {
            func_00498090(index, 3, 4);
        }
        return;
    }
    *(s16 *)((u8 *)state + 0x3BA) = 3;
    func_00498090(index, 3, 4);
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        func_00498090((u32)index < 1, 3, 4);
    }
}
