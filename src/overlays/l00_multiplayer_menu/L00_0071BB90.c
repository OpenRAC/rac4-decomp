#include "common.h"

s32 D_00220D74 = 0;
s32 D_00220D70 = 0;
extern void func_L00_00623B08(s32, s32);
extern void func_L00_00623C30(s32, s32, s32);
extern void func_L00_00623D08(s32, s32, s32, s32, s32);
extern void func_L00_0071BA48(void *, u32);

// Advances a per-side counter, stores it in the record, and sets up the first four slots.
void func_L00_0071BB90(void *arg0, u32 arg1, s32 arg2) {
    s32 var_s2;
    s32 var_v0;
    s32 temp_v1;

    if (*(u8 *)((u8 *)arg0 + 0xA9) == 1) {
        var_s2 = 4;
        var_v0 = D_00220D74 + 1;
        D_00220D74 = var_v0;
        *(s32 *)((u8 *)arg0 + 0x250) = var_v0;
    } else {
        var_s2 = 0;
        var_v0 = D_00220D70 + 1;
        D_00220D70 = var_v0;
        *(s32 *)((u8 *)arg0 + 0x250) = var_v0;
    }
    if (*(u32 *)((u8 *)arg0 + 0x250) < 4U) {
        temp_v1 = *(s32 *)((u8 *)arg0 + 0x240);
        func_L00_00623D08(var_s2, *(s32 *)((u8 *)arg0 + 0x250), temp_v1 | ((arg1 / 41) * 0x29), temp_v1 | arg1, 0);
        func_L00_00623C30(var_s2, *(s32 *)((u8 *)arg0 + 0x250), 1);
        func_L00_00623B08(var_s2, *(s32 *)((u8 *)arg0 + 0x250));
        func_L00_0071BA48(arg0, arg2);
        *(u32 *)((u8 *)arg0 + 0x258) = arg1;
    }
}
