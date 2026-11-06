#include "common.h"

typedef struct State {
    u8 prefix[0x10];
    u32 first;
    u32 second;
} State;

extern u8 D_00321140[];
extern char D_00321110[];
extern const char D_0021FCF0[];
extern u8 D_001CDB38[];
extern s32 D_00221C48;
extern s32 func_00506BB8(void);
extern s32 func_005026A8(s32 *, s32 templateId, s32 context);
extern s32 func_00506C08(s32 type, s32 group);
extern const char *func_0045E850(s32 id);
extern s32 func_0011D920(char *destination, const char *format, ...);
extern s32 func_004A2798(s32 *group, s32 index);
extern s32 func_005062D0(s32 handle, const char *text);
extern u32 func_0049A9D8(void *descriptor, s32 sector);
extern s32 func_00506590(s32 handle, u32 value);
extern s32 func_005071B8(u32 handle, u32 resource);
extern s32 func_00507270(u32 handle, s32 a, s32 b, s32 c, s32 d,
                         s32 e, s32 f, s32 g, s32 h);
extern s32 func_005060D8(u32 handle, s32 enabled);
extern s32 func_005074A0(u32 handle, s32 angle, s32 steps, f32 rate);

void func_004D9F60(void)
{
    s32 context = func_00506BB8();
    State *state = (State *)((u32)D_00321140 + (u32)context * 0x114u);
    char *destination;
    const char *format;
    const char *first;
    const char *second;
    s32 handle;
    u32 descriptor;

    func_005026A8(&D_00221C48, 0x34, -1);
    func_00506C08(15, D_00221C48);
    destination = D_00321110;
    format = D_0021FCF0;
    first = func_0045E850(0x3265);
    second = func_0045E850(0x2350);
    func_0011D920(destination, format, first, second);
    func_005062D0(func_004A2798(&D_00221C48, 8), destination);
    handle = func_004A2798(&D_00221C48, 7);
    func_005062D0(handle, func_0045E850(0x3264));
    descriptor = (u32)D_001CDB38;
    state->first = func_0049A9D8((void *)descriptor, -1);
    func_00506590(func_004A2798(&D_00221C48, 1), 1);
    func_005071B8(func_004A2798(&D_00221C48, 1), state->first);
    state->second = func_0049A9D8((void *)(descriptor + 0x6F0u), -1);
    func_00506590(func_004A2798(&D_00221C48, 0), 1);
    func_005071B8(func_004A2798(&D_00221C48, 0), state->second);
    func_00506590(func_004A2798(&D_00221C48, 2), 1);
    func_00507270(func_004A2798(&D_00221C48, 6), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221C48, 6), 1);
    func_005074A0(func_004A2798(&D_00221C48, 6), 360, 10, 0.00031f);
}
