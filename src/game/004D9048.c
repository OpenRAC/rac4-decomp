#include "common.h"

typedef struct State {
    u8 prefix[0x10];
    u32 first;
    u32 second;
} State;

extern u8 D_00321140[];
extern char D_00321110[];
extern const char D_0021FC48[];
extern u8 D_001CDAB8[];
extern s32 D_00221B48;
extern s32 func_00505B20(void);
extern s32 func_00501638(s32 *, s32 templateId, s32 context);
extern s32 func_00505B70(s32 type, s32 group);
extern const char *func_0045E038(s32 id);
extern s32 func_0011D920(char *destination, const char *format, ...);
extern s32 func_004A1A60(s32 *group, s32 index);
extern s32 func_00505238(s32 handle, const char *text);
extern u32 func_00499CA0(void *descriptor, s32 sector);
extern s32 func_005054F8(s32 handle, u32 value);
extern s32 func_00506120(u32 handle, u32 resource);
extern s32 func_005061D8(u32 handle, s32 a, s32 b, s32 c, s32 d,
                         s32 e, s32 f, s32 g, s32 h);
extern s32 func_00505040(u32 handle, s32 enabled);
extern s32 func_00506408(u32 handle, s32 angle, s32 steps, f32 rate);

void func_004D9048(void)
{
    s32 context = func_00505B20();
    State *state = (State *)((u32)D_00321140 + (u32)context * 0x114u);
    char *destination;
    const char *format;
    const char *first;
    const char *second;
    s32 handle;
    u32 descriptor;

    func_00501638(&D_00221B48, 0x34, -1);
    func_00505B70(15, D_00221B48);
    destination = D_00321110;
    format = D_0021FC48;
    first = func_0045E038(0x3265);
    second = func_0045E038(0x2350);
    func_0011D920(destination, format, first, second);
    func_00505238(func_004A1A60(&D_00221B48, 8), destination);
    handle = func_004A1A60(&D_00221B48, 7);
    func_00505238(handle, func_0045E038(0x3264));
    descriptor = (u32)D_001CDAB8;
    state->first = func_00499CA0((void *)descriptor, -1);
    func_005054F8(func_004A1A60(&D_00221B48, 1), 1);
    func_00506120(func_004A1A60(&D_00221B48, 1), state->first);
    state->second = func_00499CA0((void *)(descriptor + 0x6F0u), -1);
    func_005054F8(func_004A1A60(&D_00221B48, 0), 1);
    func_00506120(func_004A1A60(&D_00221B48, 0), state->second);
    func_005054F8(func_004A1A60(&D_00221B48, 2), 1);
    func_005061D8(func_004A1A60(&D_00221B48, 6), 1, 1, 1, 0, 0, 0, 0, 0);
    func_00505040(func_004A1A60(&D_00221B48, 6), 1);
    func_00506408(func_004A1A60(&D_00221B48, 6), 360, 10, 0.00031f);
}
