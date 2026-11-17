#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern s32 func_L00_005F6AE0(void *, s32, void *, s32, s32, s32, f32);
extern void func_L01_004C36D8(u8 *object);
extern void func_L01_0056D280(u8 *, s32, void *, u8 *, u8 *);
extern s32 func_L01_0056D620(void *arg0, s32 arg1);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern char func_L01_004C3B40[];

/* Copies the object's state from arg2 into arg0, resets its flags, runs the helper calls and sets state 3. */
void func_L01_004C3C90(void *arg0, s32 arg1, void *arg2) {
    s32 var_a2;
    u16 *var_a0;
    u16 *var_a1;
    u16 temp_a1;
    u16 temp_v0;
    u16 temp_v1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = *(void **)((u8 *)arg2 + 0xAC);
    *(u128 *)((u8 *)arg0 + 0x10) = *(u128 *)((u8 *)arg2 + 0x10);
    temp_s0 = *(void **)((u8 *)arg0 + 0xAC);
    *(u128 *)((u8 *)arg0 + 0xF0) = *(u128 *)((u8 *)arg2 + 0xF0);
    temp_a1 = *(u16 *)((u8 *)arg0 + 0x34) | (*(u16 *)((u8 *)arg2 + 0x34) & 0x8000);
    *(u16 *)((u8 *)arg0 + 0x34) = temp_a1;
    *(s32 *)((u8 *)temp_s0 + 0x138) = *(s32 *)((u8 *)temp_s2 + 0x138);
    *(f32 *)((u8 *)temp_s0 + 0x114) = *(f32 *)((u8 *)temp_s2 + 0x114);
    *((u8 *)temp_s0 + 0x461) = 0;
    *((u8 *)temp_s0 + 0x460) = 0;
    *((u8 *)temp_s0 + 0x350) = *((u8 *)temp_s2 + 0x350);
    *((u8 *)temp_s0 + 0x351) = *((u8 *)temp_s2 + 0x352);
    *(s32 *)((u8 *)temp_s0 + 0x33C) = 3;
    *(s32 *)((u8 *)temp_s0 + 0x49C) = *(s32 *)((u8 *)temp_s2 + 0x49C);
    *(u16 *)((u8 *)arg0 + 0x74) = *(u16 *)((u8 *)arg2 + 0x74);
    *((u8 *)temp_s0 + 0x4BD) = 0;
    func_L01_004C36D8(arg0);
    func_L00_005F6AE0(arg0, 2, (u8 *)func_L01_004C3B40 + 8, 0, 0, 0, 0.0f);
    temp_v1 = *(u16 *)((u8 *)temp_s2 + 0x2FC);
    var_a1 = (u16 *)((u8 *)temp_s0 + 0x300);
    var_a0 = (u16 *)((u8 *)temp_s2 + 0x300);
    var_a2 = 0xF;
    *(u16 *)((u8 *)temp_s0 + 0x2FC) = temp_v1;
    do {
        temp_v0 = *var_a0;
        var_a2 -= 1;
        var_a0 += 1;
        *var_a1 = temp_v0;
        var_a1 += 1;
    } while (var_a2 >= 0);
    func_L01_0056D620(*(u8 **)((u8 *)temp_s2 + 0x320) + 0xD0, arg0);
    func_L01_0056D280(arg0, 0, 0, 0, *(u8 **)((u8 *)temp_s2 + 0x320));
    func_L01_00591BD8(arg0, 3, -1);
}
