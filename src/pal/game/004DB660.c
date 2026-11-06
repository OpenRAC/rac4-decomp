#include "common.h"

typedef struct {
    char pad0[4];
    s32 object;
    s32 limit;
    s32 firstText;
    char pad10[4];
    s32 secondText;
} Record;

typedef struct {
    char pad0[0x34];
    char *entries;
    char pad38[0x18];
    s32 active;
    s32 index;
    char pad58[0x3C];
    s32 alternate;
} MenuState;

typedef struct {
    s32 id;
    s32 flags;
} GlobalState;

extern MenuState D_00322EA4[];
extern GlobalState D_00321B98[];
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 D_00221C78;
extern const char D_0021FD10[];

extern s32 func_004FD588(s32);
extern s32 func_004A2798(s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
extern void func_004A20D8(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_0049CCF8(s32, s32, s32, f32, f32, f32, f32);
extern void func_00462648(s32);
extern void func_00462688(s32);
extern void func_004DC0F8(s32);

void func_004DB660(void)
{
    MenuState *state;
    Record *record;
    f32 x, y, z, w;

    if (D_00322EA4[0].active != 0) {
        s32 index = D_00322EA4[0].index;
        char *entry = NULL;
        if (index >= 0) {
            entry = D_00322EA4[0].entries + index * 24;
        }
        record = *(Record **)(entry + 8);
        if (func_004FD588(index) >= record->limit) {
            func_005062D0(func_004A2798(&D_00221C78, 0x17), func_0045E850(record->firstText));
            func_005062D0(func_004A2798(&D_00221C78, 0x12), func_0045E850(record->secondText));
        } else {
            func_005062D0(func_004A2798(&D_00221C78, 0x17), func_0045E850(0x16F));
            func_005062D0(func_004A2798(&D_00221C78, 0x12), func_0045E850(0x16F));
        }
        state = D_00322EA4;
        func_004A20D8(state, &x, &y, &z, &w);
        func_0049CCF8(0, 0, 0, x, y, z, w);
        if (D_0021EE54 == 0 && D_0021EE58 == 1) {
            if (state->alternate == 0) {
                func_00462648(record->object);
            } else {
                func_00462688(record->object);
            }
        } else {
            func_00462648(record->object);
        }
        func_004DC0F8(record->object);
    } else {
        func_005062D0(func_004A2798(&D_00221C78, 0x12), func_0045E850(0x2F29));
        func_005062D0(func_004A2798(&D_00221C78, 0x17), D_0021FD10);
    }
    D_00321B98[0].flags &= ~2;
}
