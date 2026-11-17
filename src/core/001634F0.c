#include "common.h"

extern void func_00126E20(s32);
extern s32 func_00157F98(void);
extern void *D_0021DF40[];
extern void *D_0021DF48[];
extern void *D_0021DF50[];
extern void *D_0021DF58[];
extern s32 D_21D940[];

// Advances the one-slot state machine at D_21D940 by a frame, adding fparg0 to its accumulator.
void func_001634F0(f32 fparg0) {
    void *temp_s1;
    void *temp_s2;

    func_00157F98();
    if (D_21D940[1] == 0) {
        if (D_21D940[2] & 1) {
            if (((s32 (*)(void *, void *))D_0021DF40[D_21D940[5]])((u8 *)D_21D940 + 0x20, (u8 *)D_21D940 + 0x30) != 0) {
                D_21D940[1] = 1;
                D_21D940[2] = D_21D940[2] & 0xFFFFFFFE;
                *(f32 *)D_21D940 = 0.0f;
            } else {
                D_21D940[1] = 3;
            }
        } else if (D_21D940[2] & 4) {
            D_21D940[2] = D_21D940[2] & 0xFFFFFFFB;
        }
    }
    if (D_21D940[1] == 1) {
        *(f32 *)D_21D940 = *(f32 *)D_21D940 + fparg0;
        if (D_21D940[2] & 4) {
            if (((s32 (*)(void *, void *))D_0021DF50[D_21D940[5]])((u8 *)D_21D940 + 0x20, (u8 *)D_21D940 + 0x30) != 0) {
                D_21D940[1] = 4;
            }
            D_21D940[2] = D_21D940[2] & 0xFFFFFFFB;
        } else if (D_21D940[2] & 8) {
            D_21D940[1] = 3;
            D_21D940[2] = D_21D940[2] & 0xFFFFFFF7;
        } else if (((s32 (*)(void *, void *))D_0021DF48[D_21D940[5]])((u8 *)D_21D940 + 0x20, (u8 *)D_21D940 + 0x30) != 0) {
            D_21D940[1] = 2;
        }
    }
    if (D_21D940[1] == 2) {
        if (((s32 (*)(void *, void *))D_0021DF58[D_21D940[5]])((u8 *)D_21D940 + 0x20, (u8 *)D_21D940 + 0x30) != 0) {
            func_00126E20(0);
            if (D_21D940[3] != 0) {
                ((void (*)(s32, s32))D_21D940[3])(D_21D940[4], 0);
                D_21D940[1] = 0;
            } else {
                D_21D940[1] = 0;
            }
        } else {
            D_21D940[1] = 0;
            D_21D940[2] = D_21D940[2] | 1;
        }
    }
    if (D_21D940[1] == 4) {
        temp_s1 = (u8 *)D_21D940 + 0x20;
        temp_s2 = (u8 *)D_21D940 + 0x30;
        if (((s32 (*)(void *, void *))D_0021DF48[D_21D940[5]])(temp_s1, temp_s2) != 0) {
            if (((s32 (*)(void *, void *))D_0021DF58[D_21D940[5]])(temp_s1, temp_s2) != 0) {
                func_00126E20(0);
                if (D_21D940[3] != 0) {
                    ((void (*)(s32, s32))D_21D940[3])(D_21D940[4], 2);
                    D_21D940[1] = 0;
                } else {
                    D_21D940[1] = 0;
                }
            } else {
                D_21D940[1] = 3;
            }
        }
    }
    if (D_21D940[1] == 3) {
        if (D_21D940[3] != 0) {
            ((void (*)(s32, s32))D_21D940[3])(D_21D940[4], 1);
        }
        D_21D940[1] = 0;
    }
}
