#include "common.h"

extern void func_L00_005BDB08(s8 arg0);
extern void func_L00_0069D028(s32, s32);
extern s32 func_L00_0071B3C8();
extern void func_L00_0071BE28(s32 arg0, s32 arg1, u32 arg2);
extern void func_L00_0071BEB8(void *, s32, s32, s32, u32);
extern void func_L00_00748DA0(void *arg0);
extern void func_L00_00748E08(void *arg0);
extern s32 D_002212D8[];

// Set up the menu objects through their vtable slots, then run the final hooks.
void func_L00_00748930(void *arg0) {
    void *temp_a0;

    func_L00_0071BE28((s32)arg0, 0x14, 0xFFFFFFFF);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB8);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 2, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB8);
    ((void (*)(void *, void *))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0xE8))(temp_a0, D_002212D8);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB8);
    ((void (*)(void *, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x54))(temp_a0, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB0);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 1, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 1, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xBC);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 2, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xC0);
    ((void (*)(void *, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x54))(temp_a0, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xC0);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 2, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xC4);
    ((void (*)(void *, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x54))(temp_a0, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xC4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 2, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xC8);
    ((void (*)(void *, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x54))(temp_a0, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xC8);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 2, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xCC);
    ((void (*)(void *, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x54))(temp_a0, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xCC);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 2, 0);
    func_L00_0069D028(*(s32 *)((u8 *)arg0 + 0x240) | 0x10, 0);
    func_L00_0069D028(*(s32 *)((u8 *)arg0 + 0x240) | 0x11, 0);
    func_L00_0069D028(*(s32 *)((u8 *)arg0 + 0x240) | 0xF, 0);
    func_L00_0071BEB8(arg0, 0, 1, 9, 10);
    func_L00_0071BEB8(arg0, 1, 2, 3, 0xFFFFFFFF);
    func_L00_0071B3C8(arg0);
    func_L00_005BDB08(0);
    func_L00_00748DA0(arg0);
    func_L00_00748E08(arg0);
}
