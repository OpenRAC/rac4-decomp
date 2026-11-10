#include "common.h"
typedef struct {
    s32 mode;
    u32 flags;
    char pad8[0x1304];
    char context[0x6C];
    char pad1378[0x3A];
} State;
extern State D_0031B9B8;
extern u32 D_002211CC;
extern void func_005014B0(void *);
extern void func_004D5950(void);
extern void func_004D51C0(void);
extern s32 func_004A1730(void *);
extern void func_004D52D0(void);
extern void func_004D5550(void);
extern void *func_0046D820(s32);
extern f32 func_00453940(f32);
extern void func_0046E728(void *);
extern void func_0046EDD8(void *);
extern void func_004706F0(void *);
extern void func_00479820(void *, void *, s32, s32);
void func_004D4C58(void *arg0)
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
        func_004D5950();
        break;
    case 1:
        func_005014B0(arg0);
        break;
    }
    {
        State *state = &D_0031B9B8;
        if (state->flags & 1) {
            func_004D51C0();
        }
        func_004A1730(state->context);
        if (state->flags & 2) {
            func_004D52D0();
        }
        if (state->flags & 4) {
            func_004D5550();
        }
        first = func_0046D820(0);
        second = func_0046D820(1);
        if (first == NULL || second == NULL) {
            return;
        }
        phase = ((s32)D_002211CC & 0x3F) - 0x20;
        shade = (s32)(func_00453940((f32)phase * 0.09817477315664291f) * 32.0f + 96.0f);
        packed = (u32)shade;
        packed = (packed << 24) | (packed << 16) | (packed << 8) | 0x80;
        *(u32 *)((u32)first + 0x60) = packed;
        volume = (f32)((s32)(D_002211CC & 0x1FF) - 0x100) * 0.012271846644580364f;
        volume = func_00453940(volume) * 0.5f;
        *(f32 *)((u32)first + 0xF8) = volume;
        func_0046E728(first);
        func_0046EDD8(first);
        func_004706F0(first);
        *(u32 *)((u32)second + 0x60) = packed;
        volume = (f32)((s32)(D_002211CC & 0x1FF) - 0x100) * 0.012271846644580364f;
        volume = func_00453940(volume) * 0.5f;
        *(f32 *)((u32)second + 0xF8) = volume;
        func_0046E728(second);
        func_0046EDD8(second);
        func_004706F0(second);
        func_00479820(first, second, 5, 0);
    }
}
