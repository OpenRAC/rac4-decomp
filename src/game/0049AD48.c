#include "common.h"

extern void *func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern void func_0048F7E0(void *arg0);
extern void func_0048FA80(void *o);
extern void func_00497438(s32 i, s32 a, s32 b);
extern void func_0049AF68(s32 arg0);
extern void func_0049AFC0(s32 arg0);
extern void func_005014B0(s32 *a0);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 D_0021EDD4;
extern u8 D_0021EE18;
extern s32 D_0021DDB4;
extern u8 D_306DC0[];

/* Runs the pending state of the D_306DC0 entry for the current slot: wait, hand over the table, then finish. */
void func_0049AD48(s32 arg0) {
    s32 sp[7];
    s32 *var_a1;
    s32 *var_a1_2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_a2;
    s32 var_a2_2;
    void *temp_s0;
    u8 *temp_s2;
    void *temp_v0_2;
    void (*fn)(void);

    temp_v0 = func_00505B20();
    temp_s0 = func_00510BE8(temp_v0);
    temp_s2 = D_306DC0 + temp_v0 * 0x3C;
    switch (*(s32 *)(temp_s2 + 0x38)) {
    case 0:
        if (D_0021EE18 == 0 && D_0021EDD4 != 1) {
            if (D_0021DDB4 != 3) {
                return;
            }
        }
        temp_v0_2 = func_0046D428(0x2120, 0, 0xC);
        if (temp_v0_2 != NULL) {
            fn = *(void (**)(void))temp_v0_2;
            if (fn != NULL) {
                fn();
            }
        }
        func_0049AF68(temp_v0);
        *(s32 *)(temp_s2 + 0x38) = 2;
        return;
    case 1:
        *(s16 *)((u8 *)temp_s0 + 0x3BA) = 5;
        func_00497438(temp_v0, 5, 0);
        if (D_0021EDD4 == 1) {
            var_a2 = 0;
            var_a1 = sp;
            do {
                temp_v0_4 = var_a2 * 4;
                var_a2 += 1;
                *var_a1 = *(s32 *)((u8 *)*(void **)((u8 *)temp_s0 + 0x2F00) + temp_v0_4 + 0x354);
                var_a1 += 1;
            } while (var_a2 < 7);
            func_0048FA80(*(void **)((u8 *)temp_s0 + 0x2F00));
            func_0048F7E0(*(void **)((u8 *)temp_s0 + 0x2F00));
            var_a2_2 = 0;
            var_a1_2 = sp;
            do {
                temp_v0_5 = var_a2_2 * 4;
                temp_a0 = *var_a1_2;
                var_a2_2 += 1;
                var_a1_2 += 1;
                *(s32 *)((u8 *)*(void **)((u8 *)temp_s0 + 0x2F00) + temp_v0_5 + 0x354) = temp_a0;
            } while (var_a2_2 < 7);
        } else {
            func_0048FA80(*(void **)((u8 *)temp_s0 + 0x2F00));
            func_0048F7E0(*(void **)((u8 *)temp_s0 + 0x2F00));
        }
        if (*(s32 *)(temp_s2 + 0x4) == 0) {
            temp_v0_2 = func_0046D428(0x2120, 0, 0xC);
            if (temp_v0_2 != NULL) {
                fn = *(void (**)(void))((u8 *)temp_v0_2 + 0x4);
                if (fn != NULL) {
                    fn();
                }
            }
            func_005014B0((s32 *)arg0);
        }
        return;
    case 2:
        *(s16 *)((u8 *)temp_s0 + 0x3BA) = 5;
        if (*(u8 *)(temp_s2 + 0x1) != 0) {
            func_0049AFC0(temp_v0);
            *(s32 *)(temp_s2 + 0x38) = 1;
            *(u8 *)(temp_s2 + 0x1) = 0;
        }
        return;
    default:
        return;
    }
}
