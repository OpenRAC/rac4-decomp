#include "common.h"
typedef struct {
    s32 mode;
    u32 flags;
    char pad8[0x1304];
    char context[0x6C];
    char pad1378[0x3A];
} State;
extern State D_0031B9B8;
extern u32 D_002212CC;
extern void func_00502520(void *);
extern void func_004D6868(void);
extern void func_004D60D8(void);
extern s32 func_004A2468(void *);
extern void func_004D61E8(void);
extern void func_004D6468(void);
extern void *func_0046E100(s32);
extern f32 func_00454158(f32);
extern void func_0046F008(void *);
extern void func_0046F6B8(void *);
extern void func_00470FD0(void *);
extern void func_0047A158(void *, void *, s32, s32);
void func_004D5B70(void *arg0)
{
    void *first;
    void *second;
    u32 packed;
    s32 phase;
    s32 shade;
    f32 volume;
    switch (D_0031B9B8.mode) {
    case 0:
        D_0031B9B8.mode = 2;
        break;
    case 2:
        func_004D6868();
        break;
    case 1:
        func_00502520(arg0);
        break;
    }
    {
        State *state = &D_0031B9B8;
        if (state->flags & 1) {
            func_004D60D8();
        }
        func_004A2468(state->context);
        if (state->flags & 2) {
            func_004D61E8();
        }
        if (state->flags & 4) {
            func_004D6468();
        }
        first = func_0046E100(0);
        second = func_0046E100(1);
        if (first == NULL || second == NULL) {
            return;
        }
        phase = ((s32)D_002212CC & 0x3F) - 0x20;
        shade = (s32)(func_00454158((f32)phase * 0.09817477315664291f) * 32.0f + 96.0f);
        packed = (u32)shade;
        packed = (packed << 24) | (packed << 16) | (packed << 8) | 0x80;
        *(u32 *)((u32)first + 0x60) = packed;
        volume = (f32)((s32)(D_002212CC & 0x1FF) - 0x100) * 0.012271846644580364f;
        volume = func_00454158(volume) * 0.5f;
        *(f32 *)((u32)first + 0xF8) = volume;
        func_0046F008(first);
        func_0046F6B8(first);
        func_00470FD0(first);
        *(u32 *)((u32)second + 0x60) = packed;
        volume = (f32)((s32)(D_002212CC & 0x1FF) - 0x100) * 0.012271846644580364f;
        volume = func_00454158(volume) * 0.5f;
        *(f32 *)((u32)second + 0xF8) = volume;
        func_0046F008(second);
        func_0046F6B8(second);
        func_00470FD0(second);
        func_0047A158(first, second, 5, 0);
    }
}
