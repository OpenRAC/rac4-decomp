#include "common.h"

typedef struct Row {
    u8 bytes[24];
} Row;
typedef struct List {
    u8 prefix[0x2C];
    s32 handle;
    u8 rest[0x3C];
} List;
typedef struct State {
    s32 phase, dirty;
    u8 prefix[0xD04];
    Row rows[64];
    List list;
    char text[16];
    s32 value, resources[5];
    s32 field13A0;
    u8 flag13A4, flag13A5;
    u8 rest[10];
    s32 field13B0, selection, special;
    u8 flag13BC;
} State;
typedef struct Config {
    u8 prefix[0x12];
    s16 selection;
    u8 rest[0x20];
    s16 special;
} Config;
typedef void (*Renderer)(List *, Row *, s32);
typedef s32 (*Predicate)(s32);
extern State D_00321B98;
extern u8 D_00322EA4[];
extern Config D_00171BC0;
extern s32 D_0021EE54, D_0021EE58;
extern s32 D_00221C78;
extern u8 D_001CDB40[];
extern void func_004DBDD8(void);
extern void func_004A1E78(List *, Row *, s32, Renderer, s32, s32);
extern void func_004DB1F8(List *, Row *, s32);
extern void func_004A1F28(List *, Predicate);
extern s32 func_004DBBE0(s32);
extern s32 func_004A2798(s32 *, s32);
extern void func_004A1928(List *, s32, s32);
extern void func_004A1920(List *, s32);
extern s32 func_00506E68(s32, s32);
extern void func_0049DEA8(s32, s32, s32);
extern void func_0049DFB8(s32, s32);
extern void func_0049D138(s32, s32, s32, s32, s32);
extern u32 func_0049A9D8(void *, s32);
extern s32 func_00506590(s32, u32);
extern s32 func_005071B8(u32, u32);

void func_004DADC8(void)
{
    State *state;
    List *list;
    s32 group;
    u32 descriptor;
    {
        State *state = &D_00321B98;
        state->phase = 0;
        state->flag13A5 = 1;
        state->selection = D_00171BC0.selection;
        state->field13A0 = 0;
        state->flag13A4 = 0;
        state->field13B0 = 0;
        state->flag13BC = 0;
        if (D_0021EE54 == 0 && D_0021EE58 == 1) {
            state->special = D_00171BC0.special;
        }
    }
    func_004DBDD8();
    list = (List *)D_00322EA4;
    state = (State *)((u32)list - 0x130C);
    func_004A1E78(list, (Row *)((u32)list - 0x600), 64, func_004DB1F8, 46, 1);
    func_004A1F28(list, func_004DBBE0);
    func_004A1928(list, func_004A2798(&D_00221C78, 15), 0);
    func_004A1920(list, 1);
    func_00506E68(D_00221C78, list->handle);
    func_0049DEA8(0, 0, func_004A2798(&D_00221C78, 16));
    func_0049DFB8(0, 1);
    group = D_00221C78;
    func_0049D138(0, 0, group, func_004A2798(&D_00221C78, 16), 0);
    descriptor = (u32)D_001CDB40;
    state->text[0] = '0';
    state->value = 0;
    state->text[1] = 0;
    state->resources[0] = func_0049A9D8((void *)descriptor, -1);
    func_00506590(func_004A2798(&D_00221C78, 2), 1);
    func_005071B8(func_004A2798(&D_00221C78, 2), state->resources[0]);
    state->resources[1] = func_0049A9D8((void *)(descriptor - 8), -1);
    func_00506590(func_004A2798(&D_00221C78, 1), 1);
    func_005071B8(func_004A2798(&D_00221C78, 1), state->resources[1]);
    state->resources[2] = func_0049A9D8((void *)(descriptor + 0x3E8), -1);
    func_00506590(func_004A2798(&D_00221C78, 9), 1);
    func_005071B8(func_004A2798(&D_00221C78, 9), state->resources[2]);
    state->resources[4] = func_0049A9D8((void *)(descriptor + 0x70), -1);
    func_00506590(func_004A2798(&D_00221C78, 10), 1);
    func_005071B8(func_004A2798(&D_00221C78, 10), state->resources[4]);
    state->dirty = 7;
}
