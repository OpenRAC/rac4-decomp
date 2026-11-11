#include "common.h"

extern void func_001634A8(s32 repeat);
extern u32 func_00163808(s32 a0, u32 a1, u32 a2, u32 a3, u32 a4, s32 a5, s32 a6);
extern s32 *D_0021DDA4;
extern u8 D_00223610[];
extern u8 D_001C2040[];

void func_L00_00593EC8(void) {
    s32 mode = *D_0021DDA4;

    if (mode == 3) {
        u8 *s;
        func_001634A8(1);
        s = D_001C2040;
        func_00163808(0, (u32)D_00223610, *(s32 *)(s + 0xBB08) + *(s32 *)(s + 0xB444),
                      *(s32 *)(s + 0xBB0C), 0, 0, 0);
    } else if (mode == 2) {
        u8 *s;
        func_001634A8(1);
        s = D_001C2040;
        func_00163808(0, (u32)D_00223610, *(s32 *)(s + 0xBA68) + *(s32 *)(s + 0xB444),
                      *(s32 *)(s + 0xBA6C), 0, 0, 0);
        func_001634A8(1);
        func_00163808(0, (u32)(D_00223610 + 0x4800), *(s32 *)(s + 0xBA70) + *(s32 *)(s + 0xB444),
                      *(s32 *)(s + 0xBA74), 0, 0, 0);
    }
}
