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
    s32 value, unused138C;
    s32 resources[4];
    u8 rest[10];
    u8 flag;
} State;
typedef void (*Renderer)(List *, Row *, s32);
typedef s32 (*Predicate)(s32);
extern State D_0030D188;
extern s32 D_002219D8;
extern s32 D_00171BC0[];
extern u8 D_001CDB40[];
extern void func_004CA168(void);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506590(s32, u32);
extern void func_004A1E78(List *, Row *, s32, Renderer, s32, s32);
extern void func_004C9658(List *, Row *, s32);
extern void func_004A1F28(List *, Predicate);
extern s32 func_004CA030(s32);
extern void func_004A1928(List *, s32, s32);
extern void func_004A1920(List *, s32);
extern s32 func_00506E68(s32, s32);
extern void func_0049DEA8(s32, s32, s32);
extern void func_0049DFB8(s32, s32);
extern void func_0049D138(s32, s32, s32, s32, s32);
extern s32 func_00498618(char *, s32, s32);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(u32, u32);

void func_004C9250(void)
{
    State *state = &D_0030D188;
    List *list = &state->list;
    s32 group;
    u32 descriptor, endDescriptor;
    state->phase = 0;
    func_004CA168();
    func_00506590(func_004A2798(&D_002219D8, 4), 1);
    func_004A1E78(list, state->rows, 64, func_004C9658, 44, 1);
    func_004A1F28(list, func_004CA030);
    func_004A1928(list, func_004A2798(&D_002219D8, 15), 0);
    func_004A1920(list, 1);
    func_00506E68(D_002219D8, list->handle);
    func_0049DEA8(0, 0, func_004A2798(&D_002219D8, 16));
    func_0049DFB8(0, 1);
    group = D_002219D8;
    func_0049D138(0, 0, group, func_004A2798(&D_002219D8, 16), 0);
    state->value = D_00171BC0[0];
    func_00498618(state->text, state->value, 0);
    descriptor = (u32)D_001CDB40;
    endDescriptor = descriptor + 0x70;
    state->resources[0] = func_0049A9D8((void *)descriptor, -1);
    func_00506590(func_004A2798(&D_002219D8, 2), 1);
    func_005071B8(func_004A2798(&D_002219D8, 2), state->resources[0]);
    state->resources[1] = func_0049A9D8((void *)(descriptor - 8), -1);
    func_00506590(func_004A2798(&D_002219D8, 1), 1);
    func_005071B8(func_004A2798(&D_002219D8, 1), state->resources[1]);
    state->resources[2] = func_0049A9D8((void *)endDescriptor, -1);
    func_00506590(func_004A2798(&D_002219D8, 10), 1);
    func_005071B8(func_004A2798(&D_002219D8, 10), state->resources[2]);
    state->resources[3] = func_0049A9D8((void *)endDescriptor, -1);
    func_00506590(func_004A2798(&D_002219D8, 9), 1);
    func_005071B8(func_004A2798(&D_002219D8, 9), state->resources[3]);
    state->flag = 0;
    state->dirty = 7;
}
