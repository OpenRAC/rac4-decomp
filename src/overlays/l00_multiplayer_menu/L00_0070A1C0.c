#include "common.h"

extern s32 func_L00_005C9F50(s32);
extern char D_003F2290[];
s32 D_00220A10 = 0;
s32 D_00220A24 = 0;
void *D_00220A28 = 0;
void *D_00220A2C = 0;

/* Steps a 30-slot counter, then drives the two owner objects' vtable hooks with a mode value or D_003F2290. */
void func_L00_0070A1C0(void) {
    s32 temp_v0;
    void *temp_s0;

    temp_v0 = D_00220A24 + 1;
    D_00220A24 = temp_v0;
    if (temp_v0 >= 0x1E) {
        D_00220A24 = 0;
    }
    if (D_00220A28 != 0) {
        if (D_00220A10 != 0) {
            if ((u32)D_00220A24 < 0xF) {
                (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)D_00220A28 + 0x58) + 0x20))(D_00220A28, 2, 0);
                (*(void (**)(void *, s32))((u8 *)*(void **)((u8 *)D_00220A28 + 0x58) + 0x64))(D_00220A28, 0x70B6AB9E);
            } else {
                (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)D_00220A28 + 0x58) + 0x20))(D_00220A28, 2, 0);
                (*(void (**)(void *, s32))((u8 *)*(void **)((u8 *)D_00220A28 + 0x58) + 0x64))(D_00220A28, 0x80404040);
            }
        } else {
            (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)D_00220A28 + 0x58) + 0x20))(D_00220A28, 1, 0);
        }
    }
    if (D_00220A2C != 0) {
        if (D_00220A10 != 0) {
            temp_s0 = *(void **)((u8 *)D_00220A2C + 0x58);
            (*(void (**)(void *, s32))((u8 *)temp_s0 + 0xE8))(D_00220A2C, func_L00_005C9F50(0x33B9));
            (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)D_00220A2C + 0x58) + 0x20))(D_00220A2C, 2, 0);
        } else {
            (*(void (**)(void *, char *))((u8 *)*(void **)((u8 *)D_00220A2C + 0x58) + 0xE8))(D_00220A2C, D_003F2290);
        }
    }
}
