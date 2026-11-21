#include "common.h"

extern s32 func_001614A8(void);
extern s32 func_00161778(void);
extern s32 func_00152DB8(s32, void *);
extern s32 func_00161708(s32 arg0, s32 arg1, s32 arg2);
extern char D_2130B0[];
extern char D_21A8B0[];
extern s32 D_21DBFC;
extern s32 D_0021E090;
s32 D_0021E058 = 0;
s32 D_0021E050 = 0;
s32 D_0021E07C = 0;
s32 D_0021E078 = 0;
s32 D_0021E084 = 0;
s32 D_0021E08C = 0;

// Advances one of two tracked tables and notifies the subsystem with the new entry.
void func_00161CF0(void) {
    char *var_v1_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 temp_a3;
    s32 temp_a2;
    s32 temp_a0;
    s32 temp_a1;
    s32 var_a1;
    s32 var_s0;
    s32 var_v1;
    s32 *temp_v1_3;

    if (func_001614A8() == 0) {
        return;
    }
    if (func_00152DB8(1, &D_21DBFC) == 1) {
        return;
    }
    temp_v0 = func_00161778();
    if (temp_v0 == -1) {
        return;
    }
    if (temp_v0 == 0) {
        temp_v1 = D_0021E058;
        D_0021E058 = 0;
        temp_v0_2 = D_0021E084 - temp_v1;
        D_0021E084 = temp_v0_2;
        if (temp_v0_2 == 0) {
            temp_v1_2 = D_0021E08C + 1;
            if (temp_v1_2 >= 0) {
                var_v1 = ((temp_v1_2 ^ 8) == 0) ? 0 : temp_v1_2;
            } else {
                var_v1 = 8;
            }
            D_0021E08C = var_v1;
            D_0021E084 = 0x140;
        }
        var_s0 = D_0021E084;
        var_v1_2 = (D_0021E08C * 0x140) + D_21A8B0;
    } else {
        temp_a3 = D_0021E07C;
        temp_v1_3 = &D_0021E058 + D_0021E090;
        temp_a2 = *temp_v1_3;
        *temp_v1_3 = 0;
        temp_a0 = D_0021E078 - temp_a2;
        var_v1_2 = (temp_a3 * 0x780) + D_2130B0;
        D_0021E078 = temp_a0;
        if (temp_a0 == 0) {
            temp_a1 = temp_a3 + 1;
            if (temp_a1 >= 0) {
                var_a1 = ((temp_a1 ^ 0x10) == 0) ? 0 : temp_a1;
            } else {
                var_a1 = 0x10;
            }
            D_0021E07C = var_a1;
            D_0021E078 = 0x780;
        }
        var_s0 = D_0021E078;
    }
    func_00161708(temp_v0, (s32)var_v1_2, var_s0);
    if (temp_v0 == 1) {
        D_0021E050 = D_0021E050 + ((var_s0 / 320) * 0x4E20);
    }
}
