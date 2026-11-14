#include "common.h"

extern void *D_00220D14;
extern s32 func_L00_0071B550();
extern void func_L00_0071D120(void *);
extern s32 func_L00_007647B0(s32 identifier);
extern void func_L00_00764958(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3);

/* Dispatches menu event arg1 to node arg0 through its vtable; returns non-zero when the event was handled. */
s32 func_L00_0071CF00(void *arg0, s32 arg1) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_s0_2;
    s32 (*var_v1)(void *, s32);
    s32 temp_a2;
    s32 temp_flags;
    s32 temp_s0;
    s32 temp_s1;
    s32 var_a1;
    s32 var_s3;

    var_s3 = 0;
    func_L00_0071D120(arg0);
    if (arg1 == 5) {
        var_s3 = 1;
        func_L00_007647B0(0x21);
        *(s32 *)((u8 *)D_00220D14 + 0x118) = 0x1F;
    }
    if (var_s3 != 0) {
        goto block_25;
    }
    var_s3 = 0;
    if (func_L00_0071B550(arg0, arg1) != 0) {
        var_s3 = 1;
    }
    if (var_s3 != 0) {
        goto block_25;
    }
    if (arg1 == 7) {
        func_L00_007647B0(0x22);
        *(s32 *)((u8 *)D_00220D14 + 0x118) = 0x1B;
        return 1;
    }
    if (arg1 == 1 || arg1 == 14) {
        temp_a0_3 = *(void **)((u8 *)arg0 + 0xB8);
        if (((s32 (*)(void *)) *(void **)((u8 *)*(void **)((u8 *)temp_a0_3 + 0x58) + 0x124))(temp_a0_3) != 0) {
            func_L00_007647B0(4);
        } else {
            func_L00_007647B0(0x74);
        }
        temp_a0_4 = *(void **)((u8 *)arg0 + 0xB8);
        temp_s0_2 = *(void **)((u8 *)temp_a0_4 + 0x58);
        temp_s0 = ((s32 (*)(void *)) *(void **)((u8 *)temp_s0_2 + 0x90))(temp_a0_4);
        var_v1 = *(s32 (**)(void *, s32))((u8 *)temp_s0_2 + 0x88);
        var_a1 = temp_s0 - 1;
        goto block_24;
    }
    if (arg1 == 2 || arg1 == 15) {
        temp_a0_3 = *(void **)((u8 *)arg0 + 0xB8);
        if (((s32 (*)(void *)) *(void **)((u8 *)*(void **)((u8 *)temp_a0_3 + 0x58) + 0x128))(temp_a0_3) != 0) {
            func_L00_007647B0(4);
        } else {
            func_L00_007647B0(0x74);
        }
        temp_a0_4 = *(void **)((u8 *)arg0 + 0xB8);
        temp_s0_2 = *(void **)((u8 *)temp_a0_4 + 0x58);
        temp_s0 = ((s32 (*)(void *)) *(void **)((u8 *)temp_s0_2 + 0x90))(temp_a0_4);
        var_v1 = *(s32 (**)(void *, s32))((u8 *)temp_s0_2 + 0x88);
        var_a1 = temp_s0 + 1;
block_24:
        var_v1(*(void **)((u8 *)arg0 + 0xB8), var_a1);
        return 1;
    }
block_25:
    temp_a0 = *(void **)((u8 *)arg0 + 0xB8);
    temp_s1 = ((s32 (*)(void *)) *(void **)((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x90))(temp_a0);
    temp_a0_2 = *(void **)((u8 *)arg0 + 0xB8);
    temp_s0 = ((s32 (*)(void *)) *(void **)((u8 *)*(void **)((u8 *)temp_a0_2 + 0x58) + 0x8C))(temp_a0_2);
    temp_a0_2 = *(void **)((u8 *)arg0 + 0xB8);
    temp_a2 = ((s32 (*)(void *)) *(void **)((u8 *)*(void **)((u8 *)temp_a0_2 + 0x58) + 0x94))(temp_a0_2);
    temp_flags = *(s32 *)((u8 *)arg0 + 0x240);
    func_L00_00764958(temp_s1, temp_s0, temp_a2, temp_flags | 0x10, temp_flags | 0x11, temp_flags | 0xF, temp_flags | 0xE, temp_flags | 0xC);
    return var_s3;
}
