#include "common.h"

extern s32 func_L00_0071B3C8(void *arg0);
extern void func_L00_0071B8E8(void *, s32, s32);
extern void func_L00_0071BA48(void *, u32);
extern void func_L00_0071BE28(s32 arg0, s32 arg1, s32 arg2);
extern void func_L00_0071BEB8(void *, s32, s32, s32, s32);
extern void *D_00220D14;

/* Sets the menu object's flags, calls the slot hooks in turn, and selects the highlight entry. */
void func_L00_0074A2A8(void *arg0) {
    u8 temp_v0;
    s32 temp_v1;
    void *temp_a0;

    func_L00_0071BE28(arg0, 0xB, 0);
    func_L00_0071BEB8(arg0, 0x45, 1, 9, 10);
    temp_v0 = *((u8 *)D_00220D14 + 0x114);
    *((u8 *)D_00220D14 + 0x114) = 1;
    *((u8 *)arg0 + 0x260) = temp_v0;
    temp_a0 = *(void **)((u8 *)arg0 + 0xB0);
    (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 0, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB4);
    (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 4, 0);
    func_L00_0071B8E8(arg0, 1, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xB8);
    (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 4, 0);
    temp_a0 = *(void **)((u8 *)arg0 + 0xBC);
    (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x20))(temp_a0, 4, 0);
    temp_v1 = *(s32 *)((u8 *)arg0 + 0x230);
    if (temp_v1 != -1) {
        temp_a0 = *(void **)((u8 *)arg0 + (temp_v1 << 2) + 0xB0);
        func_L00_0071BA48(arg0, (*(u32 (**)(void *))((u8 *)*(void **)((u8 *)temp_a0 + 0x58) + 0x44))(temp_a0));
    } else {
        func_L00_0071BA48(arg0, 0xFFFFFFFF);
    }
    func_L00_0071B3C8(arg0);
}
