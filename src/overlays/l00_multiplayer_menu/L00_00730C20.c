#include "common.h"

extern s32 func_L00_005C9F50(s32);
extern s32 func_L00_00779598(s32, s32);
extern s32 D_002233A4;

// Sends 0xF6D to the object, then 0xF6E or 0xF6F depending on func_L00_00779598's result, and returns that result.
s32 func_L00_00730C20(void *arg0) {
    s32 temp_v0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x100) + 0x58);
    ((void (*)(void *, s32))*(void **)((u8 *)temp_s0 + 0xE8))(*(void **)((u8 *)arg0 + 0x100), func_L00_005C9F50(0xF6D));
    temp_v0 = func_L00_00779598(*(s32 *)((u8 *)D_002233A4 + 0x64), 0);
    if (temp_v0 != 0) {
        temp_s0 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x100) + 0x58);
        ((void (*)(void *, s32))*(void **)((u8 *)temp_s0 + 0xE8))(*(void **)((u8 *)arg0 + 0x100), func_L00_005C9F50(0xF6E));
    } else {
        temp_s0 = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x100) + 0x58);
        ((void (*)(void *, s32))*(void **)((u8 *)temp_s0 + 0xE8))(*(void **)((u8 *)arg0 + 0x100), func_L00_005C9F50(0xF6F));
    }
    return temp_v0;
}
